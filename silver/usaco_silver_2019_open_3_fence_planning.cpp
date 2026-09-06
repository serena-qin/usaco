#include <bits/stdc++.h>
using namespace std;
bool visited[100005];
int dfs(int& minx,int& miny,int& maxx,int& maxy,int curcow,vector<vector<int>>& arr,vector<tuple<int,int>>& locations) {
    minx=min(minx,get<0>(locations[curcow]));
    miny=min(miny,get<1>(locations[curcow]));
    maxx=max(maxx,get<0>(locations[curcow]));
    maxy=max(maxy,get<1>(locations[curcow]));
    visited[curcow]=1;
    for (int n : arr[curcow]) {
        if (!visited[n]) {
            dfs(minx,miny,maxx,maxy,n,arr,locations);
        }
    }
    return 2*(maxx-minx)+2*(maxy-miny);
}
int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int>> locations(n);
    vector<vector<int>> arr(n);
    for (int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        locations[i]=make_tuple(x,y);
    }
    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        --a; --b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int ans=INT_MAX;
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            int minx=INT_MAX,miny=INT_MAX;
            int maxx=INT_MIN,maxy=INT_MIN;
            ans=min(ans,dfs(minx,miny,maxx,maxy,i,arr,locations));
        }
    }
    cout<<ans<<endl;
}