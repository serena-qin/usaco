#include <bits/stdc++.h>
using namespace std;
bool litq[105][105];
bool vis[105][105];
vector<pair<int,int>> sw[105][105];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n;
void dfs(int x,int y){
    vis[x][y]=true;
    for(auto [a,b]:sw[x][y]){
        litq[a][b]=true;
    }
    for(int d=0;d<4;d++){
        int nx=x+dx[d], ny=y+dy[d];
        if(nx<1||ny<1||nx>n||ny>n) continue; //outofbounds checking!
        if(!litq[nx][ny]||vis[nx][ny]) continue; //makes sure its lit and not visited
        dfs(nx,ny);
    }
}
int main(){
    int m;
    freopen("lightson.in", "r", stdin);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,a,b;
        cin>> x >> y >> a >> b;
        sw[x][y].push_back({a,b});
    }
    litq[1][1]=true; //list first uhh room at entrance
    bool changed=true;
    while(changed){
        memset(vis,false,sizeof(vis)); //reset visited arr
        changed=false;
        int before=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                before += litq[i][j];
        dfs(1,1);
        int after = 0;
        for (int i=1; i<=n; i++) {
            for ( int j=1; j<=n; j++) {
                after+= litq[i][j];
            }
        }
        if(after>before) changed=true;
    }
    int ans=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            ans += litq[i][j];
        }
    }
    freopen("lightson.out", "w", stdout);
    cout << ans << endl;
}
