#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
const int mod = 9973;
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i ++) {
        for(int j = 0; j < B[0].size(); j ++) {
            for(int k = 0; k < B.size(); k ++) {
                C[i][j] = (C[i][j] + A[i][k]*B[k][j])%mod;
            }
        }
    }
    return C;
}

mat pow(mat A, int n) {
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i ++) B[i][i] = 1;
    while(n) {
        if(n&1) B = mul(B,A);
        A = mul(A,A);
        n >>= 1;
    }
    return B;
}
int main() {
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        mat A(n, vec(n));
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                cin >> A[i][j];
            }
        }
        mat B = pow(A, k);
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            ans = (ans+B[i][i])%mod;
        }
        cout << ans << endl;
    }
    return 0;
}
