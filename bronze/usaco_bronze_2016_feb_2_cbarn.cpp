#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    int min_distance = 99999999;
    int distance = 0;
    scanf("%d", &n);
    vector<int> rooms(n);
    for (int i=0; i<n; i++) {
        scanf("%d", &rooms[i]);
    }
    for (int i=0; i<n; i++) {
        distance = 0;
        int current_room = i+1;
        for (int k=1; k<n; k++) {
            distance += k * rooms[current_room%n];
            current_room += 1;
        }
        min_distance = min(distance, min_distance);
    }
    printf("%d\n", min_distance);
}
