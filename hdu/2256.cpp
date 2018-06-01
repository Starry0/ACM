#include <bits/stdc++.h>
using namespace std;
const int mod = 1024;
typedef vector<int> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i ++) {
        for(int j = 0; j < B[0].size(); j ++) {
            for(int k = 0; k < B.size(); k ++) {
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]);
            }
            C[i][j] %= mod;
        }
    }
    return C;
}

mat pow(mat A, int n) {
    mat B(A.size(), vec(A[0].size()));
    for(int i = 0; i < B.size(); i ++) B[i][i] = 1;
    while(n) {
        if(n&1) B = mul(A, B);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        mat A(2, vec(2));
        A[0][0] = 5; A[0][1] = 12;
        A[1][0] = 2; A[1][1] = 5;
        A = pow(A, n-1);
        // cout << A[0][0]*5+A[0][1]*2 << ' ' << A[1][0]*5+A[1][1]*2 << endl;
        int ans = (A[0][0]*5+A[0][1]*2)*2-1;
        cout << ans%mod << endl;
    }
    return 0;
}
