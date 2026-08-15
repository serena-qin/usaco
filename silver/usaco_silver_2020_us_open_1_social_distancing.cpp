#include <bits/stdc++.h>
using namespace std;
bool tester(int d, const vector<pair<int, int>>& intervals, int n) {
    long long last = -1e18; //last = last place you put a cow down. currently set to a sentinel value
    int cows = 0; //place first cow
    for (auto [i,j]:intervals) {
        //btw: last = the most recently placed cow's location, pos = the next  position
        long long pos = max(last+d, (long long)i); //earliest value that 1. has grass and 2. is >d. if we reach +d before grass, we have to wait till we get to grass and vice versa
        while (pos <= j) { //if this interval of grass has enough space, we might be able to put down another cow. thats why this is a loop and not just a single line "put down a cow"!
            cows++;
            if (cows >= n) return true; //did we finish all of the cows??
            last = pos; //shift forward and move on
            pos = last+d; //add interval of d
        }
    }
    return false;
}
int main() {
    int n, m;
    freopen("socdist.in", "r", stdin);
    cin >> n >> m;
    vector<pair<int,int>> intervals(m);
    int a, b;
    for (int i=0; i<m; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());
    int low=0;
    int high = 1e9;
    int mid = 0;
    while (low<=high) { //binary search, <= so the last edgecase is included
        mid = (low+high)/2;
        if (tester(mid, intervals, n)) {
            low = mid+1; //jump down
        } else {
            high = mid-1; //jump up
        }
        mid = (low+high)/2;
    }
    freopen("socdist.out", "w", stdout);
    cout << high << endl;
}
