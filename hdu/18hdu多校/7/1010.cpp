#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
const ll mod = 1e9+7;

struct mat{
	ll m[3][3];
	mat() {
		memset(m, 0, sizeof(m));
	}
};
mat mul(mat &A, mat &B) {
	mat C;
	for(int i = 0; i < 3; i ++) {
		for(int j = 0; j < 3; j ++) {
			for(int k = 0; k < 3; k ++) {
				C.m[i][j] = (C.m[i][j] + A.m[i][k]*B.m[k][j]) %mod;
			}
		}
	}
	return C;
}

mat pow(mat &A, ll n) {
	mat B;
	for(int i = 0; i < 3; i ++) B.m[i][i] = 1;
	while(n) {
		if(n&1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}

mat init(ll c, ll d, ll x) {
	mat A;
	A.m[0][0] = c, A.m[0][1] = d, A.m[0][2] = 1;
	A.m[1][0] = 1, A.m[2][2] = x;
	return A;
}
int main() {
	ll t, a, b, c, d, p, n;
	cin >> t;
	while(t--) {
		cin >> a >> b >> c >> d >> p >> n;
		if(n == 1) printf("%lld\n",a);
		else if(n < p) {
			mat A = init(c, d, 0);
			mat B = pow(A, n-2);
			ll ans = B.m[0][0]*b+B.m[0][1]*a;
			printf("%lld\n",ans%mod);
		}
	}
	return 0;
}