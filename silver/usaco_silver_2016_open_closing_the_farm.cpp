#include <bits/stdc++.h> 
using namespace std;
void dfs(int x, const vector<vector<int>> &adj, const vector<bool> &closed, vector<bool> &visited, int &vc) { 
    visited[x]=true; 
    vc++; 
    for (int n:adj[x]) { 
        if (closed[n] == false && visited[n]==false) { 
            dfs(n,adj,closed,visited,vc); 
        } 
    } 
} 
int main() { 
    freopen("closing.in", "r", stdin);
    int n,m; 
    cin>>n>>m; 
    vector<vector<int>> adj(n + 1);
    for (int i=0;i<m;i++) { 
        int a,b; 
        cin>>a>>b; 
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    } 
    freopen("closing.out", "w", stdout);
    vector<int> order(n);
    for (int i=0; i<n; i++) cin >> order[i];
    int closedcount=0; 
    vector<bool> closed(n + 1);
    for (int i=0;i<n;i++) { 
        vector<bool> visited(n + 1); 
        int vc=0;                    
        dfs(order[n-1],adj,closed,visited,vc); 
        if (vc==n-closedcount) { 
            cout<<"YES"<<endl; 
        }else { 
            cout<<"NO"<<endl; 
        } 
        int x = order[i];
        closed[x]=true; 
        closedcount++; 
    } 
}
