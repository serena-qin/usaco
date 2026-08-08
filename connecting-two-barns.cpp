//USACO 2021 December Contest, Silver Problem 2

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
    cin >> n >> m;
    vector<long long> a(2*m+1);
    vector<long long> b(2*m+1);
    vector<long long> ina(m+1);
    vector<long long> inb(m+1);
    for (long long i=0; i<n; i++) {
        long long aa, ba;
        cin >> aa >> ba;
        ina[aa]++;
        inb[ba]++;
    }
    for (long long x=0;x<=m;x++) {
        for (long long y=0; y<=m;y++) {
            a[x+y] += ina[x]*ina[y];
            b[x+y]+=inb[y]*inb[x];
        }
    }
    long long countb=0;
    long long counta=0;
    for (long long k=0; k<=2*m; k++) {
        if (k>0) countb+=b[k-1];
        counta+=a[k];
        cout << counta-countb << endl;
    }
}
