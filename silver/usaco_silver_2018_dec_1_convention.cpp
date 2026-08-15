#include <bits/stdc++.h>
using namespace std;
bool tester(int d, vector<int>&arr, int n, int m, int c) {
    //using reverse-engineered approach hehe, d=candidate max allowed diff inside a group, we're checking if this diff is formable
    int gr = 1; //groups-formed-count
    int frst = arr[0]; //wait-time of first cow in curr. bus
    int cnt = 1; //cows in curr. group/cab/bus thingy
    for (int i=1; i<n; i++) { //itr. thru remaining cows after the first cow
        if (cnt == c || arr[i]-frst>d) { //if bus is full OR adding this cow makes it exceed max wait d (cuz not all buses hafta be full!)
            gr+=1; //...then we finish this one and get a new bus
            frst = arr[i]; //reset start of new bus/cab/idk
            cnt = 1; //reset rider count to move on to a new bus
        } else {
            cnt++; //add this cow to current bus then
        }
    }
    return gr<=m;
}
int main() {
    int n, m, c;
    freopen("convention.in", "r", stdin);
    cin >> n>>m>>c;
    vector<int>arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int low = 0;
    int high = arr[n-1] - arr[0]; //range of the array
    int mid = 0;
    while (low<high) {
        mid = (low+high)/2;
        if (tester(mid, arr, n, m, c)) {
            high = mid; //jump down binary search
        } else {
            low = mid+1;
        }
    }
    freopen("convention.out", "w", stdout);
    cout << low << endl;
}
