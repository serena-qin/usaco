#include <bits/stdc++.h>
using namespace std;
bool vis[1001][1001];
int dx[4] = {-1, 1, 0,0};
int dy[4] = {0,0,-1,1};
char grid[1001][1001];
int area, perim;
void dfs(int x, int y, int n) {
    vis[x][y]=1;
    area += 1;
    for (int d=0; d<4; d++) {
        int nx = x+dx[d];
        int ny = y+dy[d];
        if (nx<0||ny>=n||ny<0||nx>=n) {
            perim += 1; //boundary check
        } else if (grid[nx][ny]=='.') {
            perim+=1; //this is an exposed side, count as perimeter!
        } else if (!vis[nx][ny]) {
            dfs(nx, ny, n); //recursion into blob. yay
        }
    }
}
int main() {
    int n;
    freopen("perimeter.in", "r", stdin);
    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    int maxa = 0;
    int peri = INT_MAX; //maxa and peri will be the things we print out in the end
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == '#' && !vis[i][j]) { //basically we're looking for a new blob, one that we haven't explored yet
                area = 0; //reset for each blob
                perim = 0; //..for bot hvariables
                dfs(i,j,n);
                if (area > maxa || (area == maxa && perim<peri)) { //info of max. blob, if blobs are equal, smallest perim (<- problem reqs for output)
                    maxa = area;
                    peri = perim;
                }
            }
        }
    }
    freopen("perimeter.out", "w", stdout);
    cout << maxa << " " << peri << endl;
}
