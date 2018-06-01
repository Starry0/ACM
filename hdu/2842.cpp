#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 200907;
struct mat{
    ll m[3][3];
    mat(){
        memset(m, 0, sizeof(m));
    }
};

mat mul(mat &A, mat &B) {
    mat C;
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++) {
            for(int k = 0; k < 3; k ++) {
                C.m[i][j] = (C.m[i][j] + A.m[i][k]*B.m[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A, int n) {
    mat B;
    for(int i = 0; i < 3; i ++) B.m[i][i] = 1;
    while(n) {
        if(n&1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
int main() {
    int n;
    while(cin >> n, n) {
        mat A;
        A.m[0][0] = A.m[0][2] = A.m[1][0] = A.m[2][2] = 1;
        A.m[0][1] = 2;
        A = pow(A, n-1);
        cout << (A.m[0][0]+A.m[0][2]) % mod << endl;
    }
    return 0;
}
