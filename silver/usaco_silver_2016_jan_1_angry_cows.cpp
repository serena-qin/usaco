#include <bits/stdc++.h>
using namespace std;
bool tester(int radius, const vector<int>& plane, int n, int k) {
    int i=0; //leftmost uncovered bale
    int cows=0; //cows used
    while (i<n) { //while not all bales covered
        cows +=1;
        int lim = plane[i] + 2*radius; //max area this radius can cover
        while (i<n && plane[i]<=lim) { 
            i += 1; //update leftmost uncovered bale
        }
    }
    return cows <= k;
}
int main() {
	int n, k;
    freopen("angry.in", "r", stdin);
    scanf("%d %d\n", &n, &k);
    vector<int> plane(n);
    for (int i=0; i<n; i++) {
        cin >> plane[i];
    }
    sort(plane.begin(), plane.end());
    int low = 0; //min poss radius
    int high = plane[n-1] - plane[0]; //max poss radius (covers the entire plane with one cowstrike!)
    int mid = 0;
    while (low < high) {
        mid = (low + high)/2;
        if (tester(mid, plane, n, k)) {
            high = mid; //jump down binary search
        } else {
            low = mid + 1; //jump up binary search, +1 to avoid infinite loop
        }
        mid = (low+high)/2;
    }
    freopen("angry.out", "w", stdout);
    printf("%d\n", low);
}
