#include<bits/stdc++.h>
using namespace std;
const int O = 2003; //O=the offset. if orig coord = (x,y), we store it as (x+O, y+O)! we have this so we nvr hafta deal with negatives
const int S = 4006; //S= size of the array/farm
bool has[S][S]; //has[x][y] = is there alr a cow here?
int dv[S][S]; //dv[x][y] = how many cows are touching this cell? (4 dir)
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int total = 0; //total number of cows currently on the grid (original + added)
bool bad(int x, int y) {
    return has[x][y]&&dv[x][y]==3; //*cow is bad, or too comfy if it has exactly 3 neighbors :), has[x][y] is to check if there actually is a cow there or not
}
void add(queue<pair<int, int>>& q, int x, int y) {
    if (bad(x,y)) q.push({x,y}); //we add turned-bad cows to the "fixing waitlist"
}
void bfs(queue<pair<int, int>>& q) {
    while (!q.empty()) {
        auto [x,y] = q.front(); //take a bad cow to fix
        q.pop();
        if (!bad(x,y)) continue; //if it's alr fixed bc we fixed a neighbor's cow or smth, jus ignore it
        int fx = -1;
        int fy = -1; 
        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (!has[nx][ny]) {
                fx = nx;
                fy = ny;
                break; //find the missing neighbor direction we need to fill in to fix the cow
            }
        }
        has[fx][fy]=1; //fix the problem with a new cow!
        total++; //count this newly added cow
        for (int i=0; i<4; i++) {
            int nx = fx+dx[i];
            int ny = fy+dy[i];
            if (has[nx][ny]) {
                dv[fx][fy]+=1; //add a cow there on record
                dv[nx][ny] += 1; //update the neighbors' counts too cuz they might be impacted
            }
        }
        add(q,fx,fy); //new cow might also become bad
        for (int i=0; i<4; i++) {
            add(q, fx+dx[i], fy+dy[i]); //...and neighbors might become bad too
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);
    for (int i=0; i<n; i++) {
        cin >> cows[i].first >> cows[i].second; //take in cow pos from input
        cows[i].first += O;
        cows[i].second += O; //shift cow coords over so we nvr use negatives! yay
    }
    for (int i=0; i<n; i++) {
        queue<pair<int, int>> q; //bfs queue
        int x=cows[i].first;
        int y = cows[i].second;
        if (!has[x][y]) { //so like i dont add a cow twice hehe
            has[x][y]=1; //place cow i.
            total++; //count original cow placement
            for (int d=0; d<4; d++) {
                int nx = x+dx[d];
                int ny = y+dy[d];
                if (has[nx][ny]) {
                    dv[x][y]++; //update this neighborcount
                    dv[nx][ny]++; //update neighborcount of neigbors! (neighbor gains this cow)
                }
            }
        }
        add(q,x,y); //check if newcow is bad
        for (int d=0; d<4; d++) {
            add(q,x+dx[d],y+dy[d]); //neighbors might become bad
        }
        bfs(q); //and now start fixing
        cout << total - (i+1) << endl; //number of cows added automatically so far
    }
}