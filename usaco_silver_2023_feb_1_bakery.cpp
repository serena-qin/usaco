#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
bool tester(ll s, ll tc, ll tm, vector<tuple<ll,ll,ll>>& friends) {
    ll low = max(0LL, s - (tm - 1));
    ll high = min(tc - 1, s);
    if (low > high) return false;
    for (auto& [a, b, d] : friends) {
        if (d <= 0) continue;
        lll rhs = (lll)d - (lll)b * s;
        ll coeff = a - b;
        if (coeff > 0) {
            if (rhs > 0) {
                ll new_low = (ll)(((lll)rhs + coeff - 1) / coeff);
                low = max(low, new_low);
            }
        } else if (coeff < 0) {
            if (rhs > 0) return false;
            else {
                ll new_high = (rhs == 0) ? 0 : (ll)(rhs / coeff);
                high = min(high, new_high);
            }
        } else {
            if (rhs > 0) return false;
        }
    }
    return low <= high;
}
void solve() {
    ll n, tc, tm;
    cin >> n >> tc >> tm;
    vector<tuple<ll,ll,ll>> friends(n);
    bool already_ok = true;
    for (auto& [a,b,d]:friends) {
        ll c;
        cin >> a >> b >> c;
        d = a * tc + b * tm - c;
        if (d>0) already_ok = false;
    }
    if (already_ok) { cout << 0 << endl; return; }
    ll low=0, high = tc+tm - 2;
    while (low<high) {
        ll mid =(low + high) / 2;
        if (tester(mid, tc, tm, friends)) high = mid;
        else low = mid + 1;
    }
    cout << low << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}