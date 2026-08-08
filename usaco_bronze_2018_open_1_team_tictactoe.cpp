#include <bits/stdc++.h>
using namespace std;

set<set<char>> S[4];

// test a line of three characters (row, column, or diagonal)
void test(char a, char b, char c) {
    set<char> s;           // store unique characters from this line
    s.insert(a);           // insert first character
    s.insert(b);           // insert second character
    s.insert(c);           // insert third character
    S[s.size()].insert(s); // add this set to S[1] if size=1, S[2] if size=2
    // ^^ set of sets
}

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    vector<vector<char>> uh(3, vector<char>(3));
    char buf[4];
    for (int i = 0; i < 3; i++) {
        scanf("%3s", buf);
        for (int j = 0; j < 3; j++) uh[i][j] = buf[j];
    }

    // hori1
    test(uh[0][0], uh[0][1], uh[0][2]);
    // hori2
    test(uh[1][0], uh[1][1], uh[1][2]);
    // hori3
    test(uh[2][0], uh[2][1], uh[2][2]);
    // verti1
    test(uh[0][0], uh[1][0], uh[2][0]);
    // verti2
    test(uh[0][1], uh[1][1], uh[2][1]);
    // verti3
    test(uh[0][2], uh[1][2], uh[2][2]);
    // diagonal upleft-downright
    test(uh[0][0], uh[1][1], uh[2][2]);
    // diagonal upright-downleft
    test(uh[0][2], uh[1][1], uh[2][0]);

    cout << S[1].size() << endl; // number of individual winners
    cout << S[2].size() << endl; // number of two-cow team winners
}
