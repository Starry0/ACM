#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
const ll mod = 2147493647;
struct mat {
    ll m[7][7];
    mat() {
        memset(m, 0, sizeof(m));
    }
};
mat mul(mat &A, mat &B) {
    mat C;
    for(int i = 0; i < 7; i ++) {
        for(int j = 0; j < 7; j ++) {
            for(int k = 0; k < 7; k ++) {
                C.m[i][j] = (C.m[i][j] + A.m[i][k]*B.m[k][j]) %mod;
            }
        }
    }
    return C;
}


mat pow(mat A, ll n) {
    mat B;
    for(int i = 0; i < 7; i ++) B.m[i][i] = 1;
    while(n) {
        if(n&1LL) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
int main() {
	ll t, n, a, b;
	cin >> t;
	mat A;
	A.m[0][0] = A.m[0][2] = 1; A.m[0][1] = 2;
	A.m[1][0] = 1;
	A.m[2][2] = A.m[2][6] = 1; A.m[2][3] = A.m[2][5] = 4; A.m[2][4] = 6;
	A.m[3][3] = A.m[3][6] = 1; A.m[3][4] = A.m[3][5] = 3;
	A.m[4][4] = A.m[4][6] = 1; A.m[4][5] = 2;
	A.m[5][5] = A.m[5][6] = A.m[6][6] = 1;
	while(t--) {
		cin >> n >> a >> b;
		if(n == 1) printf("%lld\n",a);
		else if(n == 2) printf("%lld\n",b);
		else {
			mat B = pow(A, n-2);
			ll ans = B.m[0][0]*b+B.m[0][1]*a+B.m[0][2]*81+B.m[0][3]*27+B.m[0][4]*9+B.m[0][5]*3+B.m[0][6];
			printf("%lld\n",ans%mod);
		}
	}
	return 0;
}