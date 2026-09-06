#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> parent;
vector<int> siz;
void init() {
    parent.resize(n+1);
    siz.assign(n+1,1);
    for (int i=1;i<=n;++i) {
        parent[i]=i;
    }
}
int find(int node){
    if (parent[node]==node) return node;
    return parent[node]=find(parent[node]);
}
void merge(int a, int b){
    int roota=find(a);
    int rootb=find(b);
    if (roota==rootb) return;
    if (siz[roota]<siz[rootb]) swap(roota,rootb);
    parent[rootb]=roota;
    siz[roota]+=siz[rootb];
    return;
}
int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin>>n>>m;
    init();
    vector<tuple<int,int,int>> wormholes;
    vector<int> displaced(n+1);
    bool already_sorted=true;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        if (i!=x) {
            displaced[x]=i;
            already_sorted=false;
        }
    }
    if (already_sorted) {
        cout<<-1<<endl;
        return 0;
    }
    for (int i=0;i<m;i++) {
        int a,b,w;
        cin>>a>>b>>w;
        wormholes.push_back(make_tuple(w,a,b));
    }
    sort(wormholes.begin(),wormholes.end(),greater<tuple<int,int,int>>());
    int low=0;
    int high=m-1;
    int ans=-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        int w=get<0>(wormholes[mid]);
        init();
        for (int i=0;i<=mid;i++) {
            merge(get<1>(wormholes[i]),get<2>(wormholes[i]));
        }
        bool possible=true;
        for (int i=1;i<=n;i++) {
            if (displaced[i] && find(i)!=find(displaced[i])) {
                possible=false;
                break;
            }
        }
        if (possible) {
            ans=w;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}