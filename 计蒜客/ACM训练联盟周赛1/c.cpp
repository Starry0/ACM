#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
struct mat{
    ll m[5][5];
    mat() {
        memset(m, 0, sizeof(m));
    }
};

mat mul(mat &A, mat &B) {
    mat C;
    for(int i = 0; i < 5; i ++) {
        for(int j = 0; j < 5; j ++) {
            for(int k = 0; k < 5; k ++) {
                C.m[i][j] = (C.m[i][j] + A.m[i][k]*B.m[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A, ll n) {
    mat B;
    for(int i = 0; i < 5; i ++) B.m[i][i] = 1;
    while(n) {
        if(n&1) B = mul(B,A);
        A = mul(A,A);
        n >>= 1;
    }
    return B;
}
ll pow(ll n) {
    ll x = 2, y = 1;
    while(n) {
        if(n&1) y = (y*x)%mod;
        x = x*x %mod;
        n >>= 1;
    }
    return y;
}
int main() {
    ll n;
    cin >> n;
    if(n <= 2) return 0*printf("0\n");
    else if(n == 3) return 0*printf("2\n");
    else if(n == 4) return 0*printf("7\n");
    mat A;
    A.m[0][0] = A.m[0][2] = A.m[0][3] = A.m[0][4] = 1;
    A.m[1][0] = A.m[2][1] = A.m[3][2] = A.m[4][4] = 1;
    A = pow(A, n-4);
    ll ans = (A.m[0][0]*8+A.m[0][1]*5+A.m[0][2]*3+A.m[0][3]+A.m[0][4]*2+mod)%mod;
    ans = (pow(n) - ans - 1 + mod) %mod;
    printf("%lld\n",ans);
    return 0;
}

// fn    1 0 1 1 1     fn-1
// fn-1  1 0 0 0 0     fn-2
// fn-2  0 1 0 0 0     fn-3
// fn-3  0 0 1 0 0     fn-4
//   2   0 0 0 0 1       2


