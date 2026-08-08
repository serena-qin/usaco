//USACO 2021 December Contest, Silver Problem 1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, M, N;
    vector<pair<long long, long long>> patches(K);
    for (int i = 0; i < K; i++) {
        cin >> patches[i].first >> patches[i].second;
    }
    vector<long long> nhoj(M);
    for (int i = 0; i < M; i++) {
        cin >> nhoj[i];
    }
    sort(patches.begin(), patches.end());
    sort(nhoj.begin(), nhoj.end());
    vector<long long> gains;
    int p_idx = 0;
    long long left_sum = 0;
    while (p_idx < K && patches[p_idx].first < nhoj[0]) {
        left_sum += patches[p_idx].second;
        p_idx++;
    }
    gains.push_back(left_sum);
    for (int i = 0; i < M - 1; i++) {
        long long left_nhoj = nhoj[i];
        long long right_nhoj = nhoj[i + 1];
        long long max_window_len = right_nhoj - left_nhoj;
        vector<pair<long long, long long>> curr_patches;
        long long total_interval_sum = 0;
        while (p_idx < K && patches[p_idx].first < right_nhoj) {
            curr_patches.push_back(patches[p_idx]);
            total_interval_sum += patches[p_idx].second;
            p_idx++;
        }
        long long max_one_cow = 0;
        long long current_window_sum = 0;
        int r = 0;
        for (int l = 0; l < (int)curr_patches.size(); l++) {
            while (r < (int)curr_patches.size() && 
                   2 * (curr_patches[r].first - curr_patches[l].first) < max_window_len) {
                current_window_sum += curr_patches[r].second;
                r++;
            }
            max_one_cow = max(max_one_cow, current_window_sum);
            current_window_sum -= curr_patches[l].second;
        }
        gains.push_back(max_one_cow);
        gains.push_back(total_interval_sum - max_one_cow);
    }
    long long right_sum = 0;
    while (p_idx < K) {
        right_sum += patches[p_idx].second;
        p_idx++;
    }
    gains.push_back(right_sum);
    sort(gains.rbegin(), gains.rend());
    long long total_tastiness = 0;
    for (int i = 0; i < min((int)gains.size(), N); i++) {
        total_tastiness += gains[i];
    }
    cout << total_tastiness << endl;
}
