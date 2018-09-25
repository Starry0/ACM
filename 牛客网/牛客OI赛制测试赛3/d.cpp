#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll Mod = 998244353;
ll t, len = 2, k;
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i ++) {
        for(int k = 0; k < B.size(); k ++) {
            for(int j = 0; j < B[0].size(); j ++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % Mod;
            }
        }
    }
    return C;
}
mat add(mat A, mat B) {
    mat C(len, vec(len));
    for(int i = 0; i < len; i ++) {
        for(int j = 0; j < len; j ++) {
            C[i][j] = (A[i][j] + B[i][j]) % Mod;
        }
    }
    return C;
}
mat pow(mat A, ll n) {
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i ++) {
        B[i][i] = 1;
    }
    while(n > 0) {
        if(n&1) B = mul(B,A);
        A = mul(A,A);
        n >>= 1;
    }
    return B;
}
mat dfs(mat A, ll tmp) {
    if(tmp == 1) return A;
    mat B(len, vec(len));
    mat C(len, vec(len));
    if(tmp%2 == 0) {
        B = dfs(A, tmp/2);
        C = pow(A, tmp/2);
        return add(mul(B,C), B);
    } else {
        B = dfs(A, tmp/2);
        C = pow(A, tmp/2);
        return add(pow(A, tmp), add(B, mul(C, B)));
        //add(pow(A,tmp),add(mul(pow(A,tmp/2),dfs(A,tmp/2)), dfs(A,tmp/2)));
    }
}
int main() {
    cin >> k;
    if(k == 0) return 0*printf("0\n");
    mat A(len, vec(len));
    mat B(len, vec(len));
    A[0][0] = A[0][1] = A[1][0] = 1;
    //B = add(A,A);
    B = dfs(A, k);
    printf("%lld\n",(B[0][0]+1)%Mod);
    return 0;
}