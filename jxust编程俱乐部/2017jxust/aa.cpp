#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll Mod = 9932017;

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
int main() {
	ll n, t;
	cin >> t;
	while(t--) {
		
	}
	return 0;
}