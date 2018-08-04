#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int SG[N*N], f[N];
int k, m, l, y, x;
int getSG(int n) {
    int mex[101];
    memset(mex, 0, sizeof(mex));
    if(SG[n] != -1) return SG[n];
    if(n - f[0] < 0) return SG[n] = 0;
    for(int i = 0; i < k && f[i] <= n; i ++) {
        mex[getSG(n - f[i])] = 1;
    }
    for(int i = 0; ; i ++) {
        if(!mex[i]) {
            return SG[n] = i;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> k, k) {
        for(int i = 0; i < k; i ++) cin >> f[i];
        sort(f,f+k);
        memset(SG, -1, sizeof(SG));
        SG[0] = 0;
        cin >> m;
        while(m--){
            cin >> l;
            y = 0;
            for(int j = 0; j < l; j ++) {
                cin >> x;
                y ^= getSG(x);
            }
            if(y) printf("W");
            else printf("L");
        }
        printf("\n");
    }
    return 0;
}
