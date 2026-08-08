#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    int n;
    freopen("blist.in", "r", stdin);
    scanf("%d", &n);
    int a, b, c;
    vector<int> timeline(1001, 0);
    for (int i=0; i<n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        for (int j=a-1;j<b;j++) {
            timeline[j] += c;
        }

    }
    freopen("blist.out", "w", stdout);
    printf("%d\n", *max_element(timeline.begin(), timeline.end()));
}