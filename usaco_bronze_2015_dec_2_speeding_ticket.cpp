#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int n, m;
    freopen("speeding.in", "r", stdin);
    scanf("%d %d", &n, &m);
    vector<int> road(100);
    vector<int> bessie(100);
    int a, b;
    int curset = 0;
    for (int i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        for (int j=0; j<a; j++) {
            road[curset + j] = b;
        }
        curset += a;
    }
    curset = 0;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        for (int j=0; j<a; j++) {
            bessie[curset + j] = b;
        }
        curset += a;
    }
    int exc = 0;
    for (int i=0; i<100; i++) {
        if (bessie[i] > road[i]) {
            exc = max(exc, bessie[i]-road[i]);
        }
    }
    freopen("speeding.out", "w", stdout);
    printf("%d\n", exc);
}