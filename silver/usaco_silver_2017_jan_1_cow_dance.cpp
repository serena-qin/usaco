#include <bits/stdc++.h>
using namespace std;
bool tester(int k, const vector<int>& timeline, int n, int tmax) {
    vector<int> stage(k, 0); //stage[i] = time when stageslot i becomes free!
    for (int i=0; i<n; i++) { //process each cow in order, simulating the replacement process
        int fir = 0; //first free stage slot for filling (index)
        for (int j=1;j<k;j++) {
            if (stage[j] < stage[fir]) fir=j; //if theres a spot that finishes b4 first-free-stage-slot-for-filling, update our idfirx
        }
        stage[fir] += timeline[i]; //now fill in from waitlist and update finish time
    }
    int time=0; //time = total-show-time-taken
    for (int j=0; j<k; j++) {
        time = max(time, stage[j]); //basically which is the last cow to finish? then, the show ends
    }
    return time <= tmax; //valid if within allowed time
}
int main() {
    int n, tmax;
    freopen("cowdance.in", "r", stdin);
    cin >> n >> tmax;
    vector<int> timeline(n);
    for (int i=0; i<n; i++) {
        cin >> timeline[i];
    }
    int low=0;
    int high = n;
    int mid = 0;
    while (low<high) { //binary search
        mid = (low+high)/2;
        if (tester(mid, timeline, n, tmax)) {
            high = mid; //jump down
        } else {
            low = mid+1; //jump up
        }
        mid = (low+high)/2;
    }
    freopen("cowdance.out", "w", stdout);
    cout << mid << endl;
}
