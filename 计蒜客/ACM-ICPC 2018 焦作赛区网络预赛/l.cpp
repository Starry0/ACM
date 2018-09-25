#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
int t, len = 9; 
ll n, ans;
struct mat{
    ll m[9][9];
    mat(){
        memset(m, 0, sizeof(m));
    }
};

mat mul(mat &A, mat &B) {
    mat C;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j ++) {
            for(int k = 0; k < len; k ++) {
                C.m[i][j] = (C.m[i][j] + A.m[i][k]*B.m[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A, ll n) {
    mat B;
    for(int i = 0; i < len; i ++) B.m[i][i] = 1;
    while(n) {
        if(n&1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
int main() {
	mat A;
	A.m[0][5] = A.m[0][7] = A.m[1][3] = A.m[1][5] = A.m[1][7] = 1;
	A.m[2][4] = A.m[2][6] = A.m[3][0] = A.m[3][6] = 1;
	A.m[4][1] = A.m[4][8] = A.m[5][1] = A.m[5][2] = A.m[5][8] = 1;
	A.m[6][0] = A.m[6][4] = A.m[7][3] = A.m[7][5] = A.m[8][1] = A.m[8][2] = 1;

	cin >> t;
	while(t--) {
		scanf("%lld", &n);
		if(n == 1) {
			printf("3\n");
			continue;
		}
		mat B = pow(A, n-2);
		ll ans = 0;
		for(int i = 0; i < len; i ++) {
			for(int j = 0; j < len; j ++) {
				ans = (ans + B.m[i][j]) %mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}