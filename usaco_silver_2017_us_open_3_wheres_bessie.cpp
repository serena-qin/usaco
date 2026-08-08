#include <bits/stdc++.h>
using namespace std;
int n;
string grid[21];
bool visited[21][21];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void dfs(int r, int c, int r1, int c1, int r2, int c2, char color) { //counts how many connected blobby components in subsection
    //r&c = coordinate we're on, r1 & c1 = coords of the top left corner of the rectangle, r2 & c2 = coords of the bottom-right corner of the rectangle, color = color we're exploring in the counting (dfs only spreads to cells with this same character!)
    stack<pair<int,int>> s;
    s.push({r,c}); //mark down the beginning of our floodfill "path"
    visited[r][c] = true;
    while(!s.empty()) { //while we haven't run out of uhh cells?
        pair<int, int> p = s.top(); //this part is retrieving the current cell so we can verify and travel through it
        int x = p.first;
        int y = p.second;
        s.pop();
        for (int d=0; d<4; d++) {
            int nx=x+dx[d]; //moving in all four directions
            int ny=y+dy[d];
            if (nx<r1 || nx>r2 || ny<c1 || ny>c2) continue; //boundary check!
            if (!visited[nx][ny] && grid[nx][ny] == color) { //makes sure we're not infinite-looping and that we're actually exploring the right color rn
                visited[nx][ny] = true;
                s.push({nx,ny}); //it works! let's go on!
            }
        }
    }
}
bool pclcheck(int r1, int c1, int r2, int c2) {
    set<char> s; //set of all the cells in the subset we're testing as a pcl candidate
    for (int i=r1; i<=r2; i++) {
        for (int j=c1; j<=c2; j++) {
            s.insert(grid[i][j]);
        }
    }
    if (s.size() != 2) return false; //sets cant have duplicate elements, this basically just tests if there are only to colors (letters) in the PCL candidate
    memset(visited,false,sizeof(visited)); //reset entire visited array
    map<char, int> comp; //how many connected blobs does each color hav inside the subset? char = 'A' or 'B', int = the count
    for (int i=r1; i<=r2; i++) {
        for (int j=c1; j<=c2; j++) {
            if (!visited[i][j]) {
                char color = grid[i][j];
                dfs(i,j,r1,c1,r2,c2,color); //here we iter. thru all possible subsets and run dfs on them all brute-force. yay!
                comp[color]++; //"we just found 1 connected blob of dis color"
            }
        }
    }
    bool one=false;
    bool two = false;
    for (auto &p:comp) {
        if (p.second==1) { //does the first color have just one continuous blob?
            one = true;
        }
        if (p.second>=2) { //does the second color have 2 or more continuous blobs?
            two = true;
        }
    }
    return one && two; //both cases have to be true
}
bool inside(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
    auto [a1,a2,a3,a4] = a;
    auto [b1, b2,b3,b4] = b;
    return b1 <= a1 && b2<=a2 && b3>=a3 && b4 >= a4; //so basically this function inside() is like checking whether the subselection we're checking is actually the maximal, largest PCL, cuz if there's a PCL inside another we only count the larger, outside one
}
int main() {
    freopen("where.in", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> grid[i];
    }
    vector<tuple<int, int, int, int>> pcl;
    for (int r1=0; r1<n; r1++) {
        for (int c1 = 0; c1<n; c1++) {
            for (int r2 = r1; r2<n; r2++) {
                for (int c2=c1; c2<n;c2++) {
                    if (pclcheck(r1,c1,r2,c2)) {
                        pcl.push_back({r1,c1,r2,c2});
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i=0; i<pcl.size(); i++) {
        bool uhok = true;
        for (int j=0; j<pcl.size(); j++) {
            if (i==j) continue;
            if (inside(pcl[i], pcl[j])) {
                uhok = false;
                break;
            }
        }
        if (uhok) ans++;
    }
    freopen("where.out", "w", stdout);
    cout << ans << endl;
}