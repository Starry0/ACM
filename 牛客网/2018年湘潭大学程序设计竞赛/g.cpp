#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1000000007;
struct mat {
    ll m[6][6];
    mat() {
        memset(m, 0, sizeof(m));
    }
};

mat mul(mat &A, mat &B) {
    mat C;
    for(int i = 0; i < 6; i ++) {
        for(int j = 0; j < 6; j ++) {
            for(int k = 0; k < 6; k ++) {
                C.m[i][j] = (C.m[i][j] + A.m[i][k]*B.m[k][j]) %mod;
            }
        }
    }
    return C;
}


mat pow(mat A, ll n) {
    mat B;
    for(int i = 0; i < 6; i ++) B.m[i][i] = 1;
    while(n) {
        if(n&1LL) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
int main() {
    int t;
    cin >> t;
    mat A;
    for(int i = 0; i < 6; i ++) A.m[0][i] = 1;
    A.m[1][0] = A.m[2][2] = A.m[2][5] = 1;
    A.m[3][3] = A.m[3][5] = A.m[4][4] = 1;
    A.m[4][5] = A.m[5][5] = 1;
    A.m[2][3] = A.m[2][4] = 3;
    A.m[3][4] = 2;
    while(t--) {
        ll n;
        cin >> n;
        mat B =pow(A, n-1);
        ll ans = B.m[0][0]+B.m[0][2]*8+B.m[0][3]*4+B.m[0][4]*2+B.m[0][5];
        cout << ans%mod << endl;
    }
    return 0;
}
