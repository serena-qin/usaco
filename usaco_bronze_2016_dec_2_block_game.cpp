#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n;
    scanf("%d", &n);
    vector<vector<string>> boards(n);
    vector<int> x(26);
    vector<int> y(26);
    vector<int> z(26);
    vector<char> alphabet = {
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'
    };
    for (int i=0; i<n; i++) {
        string a, b;
        cin >> a >> b;
        boards[i].push_back(a);
        boards[i].push_back(b);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<26; k++) {
                x[k] = count(boards[i][j].begin(), boards[i][j].end(), alphabet[k]);
                y[k] = max(x[k], y[k]);
            }
        }
        for (int j=0; j<26; j++) {
            z[j] += y[j];
            y[j] = 0;
        }
    }
    for (int j=0; j<26; j++) {
        printf("%d\n", z[j]);
    }
}
/*
For each pair of strings, count the frequency of each letter in both strings separately.

For each letter, take the maximum frequency from the two strings (because either string may be needed).

Add that maximum to a running total across all pairs.

After all pairs, the running total is the minimum number of each letter required to cover all choices.*/