#include <iostream>
#include <vector>
using namespace std;
int main() {
    freopen("paint.in", "r", stdin);
    int a;
    int b;
    int c;
    int d;
    vector<bool> fence(100, false);
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    for (int i=a; i<b; i++) {
        fence[i] = true;
    }
    for (int i=c; i<d; i++) {
        fence[i] = true;
    }
    int count = 0;
    for (int i=0; i<100; i++) {
        if (fence[i] == true) count += 1;
    }
    freopen("paint.out", "w", stdout);
    printf("%d\n", count);
}