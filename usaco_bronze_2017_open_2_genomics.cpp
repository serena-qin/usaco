#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int cowcount, genecount;
    cin >> cowcount >> genecount;
    vector<vector<char>> spottycows(cowcount);
    vector<vector<char>> plaincows(cowcount);
    for (int i=0; i<cowcount; i++) {
        spottycows[i].resize(genecount);
        for (int j=0; j<genecount; j++) {
            cin >> spottycows[i][j];
        }
    }
    for (int i=0; i<cowcount; i++) {
        plaincows[i].resize(genecount);
        for (int j=0; j<genecount; j++) {
            cin >> plaincows[i][j];
        }
    }
    vector<char> spotcowmini;
    vector<char> plaincowmini;
    int finalle = 0;
    int counte = 0;
    for (int i=0; i<genecount; i++) {
        spotcowmini.clear();
        plaincowmini.clear();
        counte = 0;
        for (int j=0; j<cowcount; j++) {
            spotcowmini.push_back(spottycows[j][i]);
            plaincowmini.push_back(plaincows[j][i]);
        }
        for (int j=0; j<cowcount; j++) {
            if (count(plaincowmini.begin(), plaincowmini.end(), spotcowmini[j]) == 0) counte += 1;
        }
        if (counte == cowcount) finalle += 1;
    }
    cout << finalle << endl;
} 