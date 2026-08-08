#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;
int main() {
    int n;
    freopen("traffic.in", "r", stdin);
    scanf("%d", &n);
    vector<tuple<string, int, int>> road;
    for (int i=0; i<n; i++) {
        string a;
        int b, c;
        cin >> a >> b >> c;
        road.push_back(make_tuple(a, b, c));
    }
    int low = -100000, high = 1000000;
    for (int i=n-1; i>=0; i--) {
        string t;
        int a;
        int b;
        tie(t,a,b) = road[i];
        if (t == "none") {
            low = max(low, a);
            high = min(high, b);
        } else if (t == "on") {
            low -= b;
            high -= a;
        } else {
            low += a;
            high += b;
        }
        low = max(0,low); //not neg
        high = min(1000, high); //not > problem constraints
    }
    freopen("traffic.out", "w", stdout);
    printf("%d %d\n", low, high);
    low = -100000;
    high = 100000;
    for (int i=0; i<n; i++) {
        string t;
        int a, b;
        tie(t,a,b) = road[i];
        if (t == "none") {
            low = max(low,a);
            high = min(high,b);
        } else if (t == "on") {
            low += a;
            high += b;
        } else {
            low = max(0, low - b);
            high = max(0, high - a);
        }
        low = max(0, low);
        high = min(1000, high);
    }
    printf("%d %d\n", low, high);
}