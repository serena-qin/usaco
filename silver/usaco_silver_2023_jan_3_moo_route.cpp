#include <bits/stdc++.h>
using namespace std;
vector<int> a; //input, bessie's -.5 traversals
string ans; //final answer, bessie's ultimate path

void solve(int l, int r, char dir) {
    
}
string ans;

void solve(int l, int r, char dir) {
    if (l > r) return;

    bool any = false;
    for (int i = l; i <= r; i++) {
        if (a[i] > 0) {
            any = true;
            break;
        }
    }
    if (!any) return;

    for (int i = l; i <= r; i++)
        a[i] /= 2;

    solve(l, r - 1, 'R');
    ans += dir;
    solve(l, r - 1, 'L');
}

int main() {
    int N;
    cin >> N;

    a.resize(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    solve(0, N - 1, 'R');

    cout << ans << endl;
}
