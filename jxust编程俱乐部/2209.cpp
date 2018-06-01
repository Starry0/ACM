#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 9932017;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll a[4966010];
struct Nod{
	ll mat[2][2];
	Nod(){
		mat[0][0] = mat[0][1] = 0;
		mat[1][0] = mat[1][1] = 0;
	}
};
Nod mul(Nod &A, Nod &B) {
    Nod C;
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < 2; j ++) {
            for(int k = 0; k < 2; k ++) {
                C.mat[i][j] = (C.mat[i][j] + A.mat[i][k]*B.mat[k][j]) % mod;
            }
        }
    }
    return C;
}

Nod pow(Nod A, ll n) {
	Nod B;
    for(int i = 0; i < 2; i ++) B.mat[i][i] = 1;
    while(n) {
        if(n&1LL) B = mul(B,A);
        A = mul(A, A);
        n >>= 1LL;
    }
    return B;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    // cin >> t;
    scanf("%d",&t);
    while(t--) {
        ll n;
        // cin >> n;
        scanf("%lld",&n);
        n %= 4966009;
		if(n > 2483005) n = 2483005*2-n-1;
        if(n == 0) {
            printf("1\n");
            continue;
        }
        if(a[n]) {
            printf("%lld\n",a[n]);
            continue;
        }
		Nod A;
		A.mat[0][0] = A.mat[1][1] = 11;
		A.mat[0][1] = 60;
		A.mat[1][0] = 2;
		A = pow(A, n-1);
		ll ans = A.mat[0][0]*11+A.mat[0][1]*2;
        printf("%lld\n",(2*ans-1)%mod);
        a[n] = (2*ans-1)%mod;
    }
    return 0;
}
