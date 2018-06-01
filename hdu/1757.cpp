#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
int k, m;
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i ++) {
        for(int j = 0; j < B[0].size(); j ++) {
            for(int k = 0; k < B.size(); k ++) {
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % m;
            }
        }
    }
    return C;
}
mat pow(mat A, int n) {
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i ++) {
        B[i][i] = 1;
    }
    while(n > 0) {
        if(n&1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
int main() {
    mat A(10,vec(10));
    for(int i = 0; i < 9; i ++) {
        A[i+1][i] = 1;
    }
    while(cin >> k >> m) {
        for(int i = 0; i < 10; i ++) cin >> A[0][i];
        if(k < 10) {
            cout << (k%m) << endl;
            continue;
        }
        mat B = pow(A, k - 9);
        int ans = 0;
        for(int i = 0; i < 10; i ++) {
            ans += (B[0][i]*(9-i))%m;
        }
        cout << ans%m << endl;
    }
    return 0;
}
