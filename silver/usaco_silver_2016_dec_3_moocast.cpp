#include <bits/stdc++.h>
using namespace std;
int idk(int n, vector<bool> &visited, double (&dists)[200][200], vector<tuple<int,int,int>> &points) {
    int count=1;
    visited[n]=true;
    for (int i=0; i<points.size();i++) {
        if (visited[i]==false && dists[n][i] <=get<2>(points[n])) {
            count+=idk(i,visited,dists,points);
        }
    }
    return count;
}
int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
	int n;
    cin>>n;
    double dists[200][200];
    vector<tuple<int,int,int>> points(n);
    for (int i=0; i<n;i++) {
        int x,y,p;
        cin>>x>>y>>p;
        points[i] = make_tuple(x,y,p);
    }
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            dists[i][j]=sqrt((get<0>(points[i])-get<0>(points[j]))*(get<0>(points[i])-get<0>(points[j])) + (get<1>(points[i])-get<1>(points[j]))*(get<1>(points[i])-get<1>(points[j])));
            dists[j][i]=dists[i][j];
        }
    }
    vector<bool> visited(n);
    int ans=INT_MIN;
    for (int i=0;i<n;i++) {
        vector<bool> visited(n,false);
        ans = max(ans,idk(i,visited,dists,points));
    }
    cout<<ans<<endl;
}
