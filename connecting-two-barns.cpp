//USACO 2021 December Contest, Silver Problem 2

#include <bits/stdc++.h>
using namespace std;

vector<int> onegroup;
vector<int> ngroup;
vector<int> comp;
void dfs(int x, int id, const vector<vector<int>>& adj) {
    comp[x] = id;
    for (int destination : adj[x]) {
        if (comp[destination] == 0) {
            dfs(destination, id, adj);
        }
    }
}
long long binary_search(int w) {
    if (onegroup.empty()) return 1e18;
    auto it = lower_bound(onegroup.begin(), onegroup.end(), w);
    long long best = 1e18;
    if (it != onegroup.end()) {
        long long diff = *it-w;
        best = min(best, diff * diff);
    }
    if (it != onegroup.begin()) {
        long long diff = *(it - 1) - w;
        best = min(best,diff*diff);
    }
    return best;
}
long long binary_searchn(int w) {
    if (ngroup.empty()) return 1e18;
    auto it = lower_bound(ngroup.begin(), ngroup.end(), w);
    long long best = 1e18;
    if (it != ngroup.end()) {
        long long diff = *it-w;
        best = min(best, diff *diff);
    }
    if (it != ngroup.begin()) {
        long long diff = *(it-1)-w;
        best = min(best, diff*diff);
    }
    return best;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        onegroup.clear();
        ngroup.clear();
        int j, k;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            cin >> j >> k;
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        comp.assign(n + 1, 0);
        int current_id = 0;
        for (int i = 1; i <= n; i++) {
            if (comp[i] == 0) {
                current_id++;
                dfs(i, current_id, adj);
            }
        }
        if (comp[1] == comp[n]) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (comp[i] == comp[1]) onegroup.push_back(i);
            if (comp[i] == comp[n]) ngroup.push_back(i);
        }
        sort(onegroup.begin(), onegroup.end());
        sort(ngroup.begin(), ngroup.end());
        vector<long long> comp_cost1(current_id + 1, 1e18);
        vector<long long> comp_costn(current_id + 1, 1e18);
        for (int i = 1; i <= n; i++) {
            int c = comp[i];
            comp_cost1[c] = min(comp_cost1[c], binary_search(i));
            comp_costn[c] = min(comp_costn[c], binary_searchn(i));
        }
        vector<long long> prices(current_id + 1);
        for (int i = 1; i <= current_id; i++) {
            prices[i] = comp_cost1[i] + comp_costn[i];
        }
        cout << *min_element(prices.begin() + 1, prices.end()) << endl;
    }
}