// an = 2*a(n-1)+4^(n-1)
// 设向上的有Xn，向下有Yn
// 那么有：
// Xn = 3*X(n-1) + Y(n-1)
// Yn = X(n-1) + 3*Y(n-1)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1000000007;
struct mat{
    ll m[2][2];
    mat(){
        memset(m, 0, sizeof(m));
    }
};

mat mul(mat &A, mat &B) {
    mat C;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j ++) {
            for(int k = 0; k < 2; k ++) {
                C.m[i][j] = (C.m[i][j] + A.m[i][k]*B.m[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A, ll n) {
    mat B;
    for(int i = 0; i < 2; i ++) B.m[i][i] = 1;
    while(n) {
        if(n&1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
int main() {
    ll n;
    cin >> n;
    mat A;
    A.m[0][0] = A.m[1][1] = 3;
    A.m[0][1] = A.m[1][0] = 1;
    A = pow(A, n);
    cout << A.m[0][0]<< endl;
    return 0;
}
