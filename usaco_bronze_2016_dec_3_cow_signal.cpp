#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m=0, n=0, k=0;
    freopen("cowsignal.in", "r", stdin);
    cin >> m >> n >> k;
    vector<vector<char>> v(m);
    for (int i=0; i<m; i++) {
        v[i].resize(n);
    }
    string ph;
    for (int i=0; i<m; i++) {
        cin >> ph;
        for (int j=0; j<n; j++) {
            v[i][j] = ph[j];
        }
    }
    vector<vector<char>> s(m*k);
    for (int i=0; i<m*k; i++) {
        s[i].resize(n*k);
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            for (int a=0; a<k; a++) {
                for (int b=0; b<k; b++) {
                    s[(k*i) + a][(k*j) + b] = v[i][j];
                }
            }
        }
    }
    freopen("cowsignal.out", "w", stdout);
    for (int i=0; i<m*k; i++) {
        for (int j=0; j<n*k; j++) {
            cout << s[i][j];
        }
        cout << endl;
    }
}