#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("gates.in","r",stdin);
    freopen("gates.out","w",stdout);
    int n;
    int x=0,y=0; //strting pt
    string s;
    cin>>n>>s;
    set<pair<int,int>> v;//vertices!!
    set<tuple<int,int,int,int>> e;//edges
    v.insert({x,y});
    for (char c:s) {
        int nx=x,ny=y;//nx=new-x,etc
        if(c=='N')ny++;
        if(c=='S')ny--;
        if(c=='E')nx++;
        if(c=='W')nx--;
        v.insert({nx,ny});
        if(make_pair(x,y)<make_pair(nx,ny)){//so we're just reordering to prevent repeats that arent counted cuz ordr here
            e.insert({x,y,nx,ny});
        } else{
            e.insert({nx,ny,x,y});
        }
        x=nx;
        y=ny;
    }
    cout<<e.size()-v.size()+1<<endl;//euclid coplanar
}
