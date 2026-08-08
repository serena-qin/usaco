#include <bits/stdc++.h> 
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> r(N);
    for (int i=0; i<N; i++) {
        r[N].resize(N);
    }
    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {
            cin >> r[i][j];
        }
    }
    
}
'''
read N
read r[i][j]

set a[N] = 0

for i = N-1 down to 1:
    a[i] = a[i+1] + r[i][i+1]

    if a[i] does not make all ranges r[i][i...N] correct:
        a[i] = a[i+1] - r[i][i+1]

shift all values so the minimum value is 0

output a

min = infinity
max = -infinity

for j = i to N:
    update min and max using a[j]

    if max - min != r[i][j]:
        return false

return true
'''