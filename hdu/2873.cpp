#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int sg[N][N], mex[N*100], n, m;
char ch;
int SG(int x, int y) {
    memset(mex, 0, sizeof(mex));
    for(int i = 0; i < x; i ++) {
        for(int j = 0; j < y; j ++) {
            mex[sg[x][j]^sg[i][y]] = 1;
        }
    }
    for(int i = 0; ; i ++) if(!mex[i]) return i;
}
int main() {
    for(int i = 0; i < N; i ++) sg[0][i] = sg[i][0] = i;
    for(int i = 1; i < N; i ++) {
        for(int j = 1; j < N; j ++) {
            sg[i][j] = SG(i,j);
        }
    }
    while(cin >> n >> m, n, m) {
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                cin >> ch;
                if(ch == '#') ans ^= sg[i][j];
            }
        }
        printf(ans?"John\n":"Jack\n");
    }
    return 0;
}
