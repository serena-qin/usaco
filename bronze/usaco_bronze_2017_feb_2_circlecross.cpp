#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<char> crossings(52);
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    for (int i=0; i<52; i++) {
        cin >> crossings[i];
    }
    vector<char> alphabet = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    int count = 0;
    int start1, end1, start2, end2;
    for (int i=0; i<26; i++) {
        for (int j=i+1; j<26; j++) {
            start1 = find(crossings.begin(), crossings.end(), alphabet[i]) - crossings.begin();
            crossings.erase(crossings.begin() + start1);
            end1 = find(crossings.begin(), crossings.end(), alphabet[i]) - crossings.begin() + 1;
            crossings.insert(crossings.begin() + start1, alphabet[i]);
            start2 = find(crossings.begin(), crossings.end(), alphabet[j]) - crossings.begin();
            crossings.erase(crossings.begin() + start2);
            end2 = find(crossings.begin(), crossings.end(), alphabet[j]) - crossings.begin() + 1;
            crossings.insert(crossings.begin() + start2, alphabet[j]);
            if ((start1 < start2 && start2 < end1 && end1 < end2) || (start2 < start1 && start1 < end2 && end2 < end1)) count += 1;
        }
    }
    cout << count << endl;
}
