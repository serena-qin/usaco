#include <bits/stdc++.h>
using namespace std;
int n, k, r;
int comp[105][105];
bool vis[105][105];
vector<pair<int,int>> cows;
set<pair<pair<int,int>, pair<int,int>>> blocked;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int cid = 0;
void dfs(int x,int y){
    vis[x][y]=true;
    comp[x][y]=cid;
    for(int d=0; d<4; d++){ //try all 4 dir
        int nx = x+dx[d];
        int ny = y+dy[d]; //neighb cell coords
        if(nx<1||ny<1||nx>n||ny>n) continue; //boundaries??
        if(vis[nx][ny]) continue; //alr visited??
        if(blocked.count({{x,y},{nx,ny}})) continue; //road blocks :D
        dfs(nx,ny);
    }
}
int main(){
    freopen("countcross.in", "r", stdin);
    cin >> n >> k >> r;
    for(int i=0;i<r;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d; //road between a,b and c,d
        blocked.insert({{a,b},{c,d}});
        blocked.insert({{c,d},{a,b}});
    }
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y; //cow positions
        cows.push_back({x,y});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j]){
                cid++;
                dfs(i,j);
            }
        }
    }
    unordered_map<int,int> cnt; //unorderedmap
    for(auto &c : cows){
        cnt[comp[c.first][c.second]]++;
    }
    long long total = (long long)k * (k - 1) / 2; //combinations, C(K,2)
    long long ans = 0;
    for (auto &p : cnt) {
        long long x = p.second;
        ans += x * (x - 1) / 2;
    }
    freopen("countcross.out", "w", stdout);
    cout <<total-ans<< endl;
}
