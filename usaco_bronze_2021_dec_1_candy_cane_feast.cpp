#include <bits/stdc++.h>
using namespace std;

long long digestion(long long cane, long long cow, long long base) {
    if (cow <= base) return 0;
    return min(cane, cow)-base;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> incow;
    vector<long long> canes;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        incow.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        canes.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        long long base =0;
        for (int j=0;j<n; j++) {
            if (base >= canes[i]) break;
            long long koi = digestion(canes[i], incow[j], base);
            base += koi;
            incow[j] += koi;
        }
    }
    for (long long k : incow) cout << k << endl;
}