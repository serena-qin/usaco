#include <bits/stdc++.h>
using namespace std;

int main() {
	int sessioncount, cowcount;
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    scanf("%d %d", &sessioncount, &cowcount);
    vector<vector<int>> v(cowcount);
    vector<vector<int>> inp(sessioncount);
    int x;
    for (int i=0; i<sessioncount; i++) {
        for (int j=0; j<cowcount; j++) {
            cin >> x;
            inp[i].push_back(x);
        }
    }
    int findcow;
    for (int cow=1; cow<=cowcount; cow++) {
        for (int sesh=0; sesh<sessioncount; sesh++) {
            findcow = find(inp[sesh].begin(), inp[sesh].end(), cow) - inp[sesh].begin();
            for (int i=findcow + 1; i<cowcount; i++) {
                v[cow - 1].push_back(inp[sesh][i]);
            }
        }
    }
    int finale = 0;
    for (int cow=0; cow<cowcount; cow++) {
        for (int cowuh=1; cowuh<=cowcount; cowuh++) {
            if (count(v[cow].begin(), v[cow].end(), cowuh) == sessioncount) finale += 1;
        }
    }
    cout << finale << endl;
}
