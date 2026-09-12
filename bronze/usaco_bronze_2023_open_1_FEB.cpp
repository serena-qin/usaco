#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mn=0;
    int mx=0;
    vector<int> defd;
    if (count(s.begin(),s.end(),'F')==n)s[0]='E';
    for (int i=0;i<n;i++) {
        if (s[i]!='F') defd.push_back(i);
    }
    int trlsf=defd[0]+(n-1-defd.back());
    for (int i=0;i<(int)defd.size()-1;i++) { //4 cases: factor 1: is length between two nonF values even or odd, factor2: are the characters Fs being sandwichd are different or same
        int a=defd[i];
        int b=defd[i+1];
        int ad = s[a]!=s[b];
        int doh=(b-a)%2;
        mn+=ad^doh;
        mx+=(b-a-ad);
        //if u fill all the intermediate Fs perfectly to match each other
        //the maximum number of matching pairs u can get==distance between them 
        //(b - a),minus 1 if the 2 endpoints s[a] and s[b] r different 
        //(then its forced to have one mismatch).
    }
    //stepsizing: 2 if no outer wildcards exist, 1 if they do basically (think about it..)
    vector<int> ans;
    int stepsz;
    if (trlsf==0) {
        stepsz=2;
    }else{
        stepsz=1;
    }
    for (int i=mn;i<=mx+trlsf;i+=stepsz){
        ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for (int val:ans) cout<<val<<endl;
}