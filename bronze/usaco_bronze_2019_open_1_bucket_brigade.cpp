#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    freopen("buckets.in", "r", stdin);
    vector<vector<char>> f(10, vector<char>(10));
    string row;
    int tarx=-1, tary=-1;
    int curx=-1, cury=-1, rockx=-1,rocky=-1;
    int cows = 0;
    for (int i=0; i<10; i++) {
        cin >> row;
        for (int j=0; j<10; j++) {
            f[i][j] = row[j];
        }
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (f[i][j] == 'B') { tarx = i; tary = j; }
            if (f[i][j] == 'L') { curx = i; cury = j; }
            if (f[i][j] == 'R') { rockx = i; rocky = j; }
        }
    }
    int dist_bl = abs(tarx - curx) + abs(tary - cury);
    int dist_br = abs(tarx - rockx) + abs(tary - rocky);
    //if the total distance from B→L equals B→R + R→L, it means the rock is directly in line between B and L. 
    // If so, you need one extra move to go around the rock.
    int dist_rl = abs(rockx - curx) + abs (rocky-cury);

    freopen("buckets.out", "w", stdout);
    if ((tarx == curx || tary == cury) && dist_bl == dist_br + dist_rl) { //checks if normal manhatten path is blocked by rock
        cout << dist_bl + 1 << endl; //xtra step to go around rock
    } else {
        cout << dist_bl - 1 << endl; // remember to take out the starting square "step"
    }
}
