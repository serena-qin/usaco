#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    int n, k;
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    scanf("%d %d", &n, &k);
    vector<string> words(n);
    for (int i=0; i<n; i++) {
        cin >> words[i];
    }
    freopen("word.out", "w", stdout);
    int char_used = 0;
    for (int i=0;i<n;i++) {
        cout << words[i];
        char_used += words[i].size();
        if (i != n-1) {
            if (char_used + words[i+1].size() > k) {
                cout << endl;
                char_used = 0;
            } else {
                cout << " ";
            }
        } else {
            cout << endl;
        }
    }
}
