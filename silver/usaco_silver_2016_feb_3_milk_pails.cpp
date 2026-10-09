#include <bits/stdc++.h>
using namespace std;
int visited[105][105];
int closest=INT_MAX;
void dfs(int mx, int my, int x,int y,int k, int m, int count) {
    closest = min(closest, abs(x+y-m));
    if (count>k||visited[x][y]>0&&visited[x][y]<=count+1) {
        return;
    }
    visited[x][y]=count;
    if (count==k) return;
    dfs(mx,my,mx,y,k,m,count+1);
    dfs(mx,my,x,my,k,m,count+1);
    dfs(mx,my,0,y,k,m,count+1);
    dfs(mx,my,x,0,k,m,count+1);
    int fillx=min(x,my-y);
    int filly=min(y,mx-x);
    dfs(mx,my,x-fillx,y+fillx,k,m,count+1);
    dfs(mx,my,x+filly,y-filly,k,m,count+1);
}
int main() {
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);
    for (int i=0;i<105;i++) {
        for (int j=0;j<105;j++) {
            visited[i][j]=-1;
        }
    }
	int x,y,k,m;
    cin>>x>>y>>k>>m;
    dfs(x,y,0,0,k,m,0);
    cout<<closest<<endl;
}
