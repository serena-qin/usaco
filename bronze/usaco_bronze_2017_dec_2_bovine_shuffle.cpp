#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    int n;
    freopen("shuffle.in", "r", stdin);
    scanf("%d", &n);
    vector<int> order(n);
    vector<int> cows(n);
    for (int i=0; i<n; i++) {
        scanf("%d", &order[i]);
        order[i] -= 1;
    }
    vector<int> history(n);
    for (int i=0; i<n; i++) {
        scanf("%d", &cows[i]);
        history[i] = cows[i];
    }
    int inde;
    for (int i=0; i<3; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if (order[k] == j) {
                    inde = k;
                    history[k] = cows[j];
                    break;
                }
            }
        }
        for (int k=0; k<n; k++) {
            cows[k] = history[k];
        }
    }
    freopen("shuffle.out", "w", stdout);
    for (int i=0; i<n; i++) {
        printf("%d\n", cows[i]);
    }
}
