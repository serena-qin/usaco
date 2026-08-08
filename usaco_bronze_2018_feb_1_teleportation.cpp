#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    freopen("teleport.in", "r", stdin);
    int a;
    int b;
    int x;
    int y;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    int value = 0;
    if (abs(a-x) < abs(a-y)) {
        value += abs(a-x);
        value += abs(b-y);
    } else {
        value += abs(a-y);
        value += abs(b-x);
    }
    int ohum = abs(b-a);
    freopen("teleport.out", "w", stdout);
    printf("%d\n", min(ohum, value));
}