#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
const ll mod = 1e9+7;
ll fac[N], inv[N];

ll pow_mod(ll x, ll n){  
    ll res=1;  
    while(n>0){  
        if(n&1)res=res*x%mod;  
        x=x*x%mod;  
        n>>=1;  
    }  
    return res;  
}
ll C(int a, int b) {
	if(a < 0 || b < 0 || a < b) return 0;
	return fac[a] * inv[b] % mod * inv[a-b] % mod;
}

int main() {
	int mx = N-1;
	fac[0] = 1;for(int i = 1; i <= mx; i ++) fac[i] = fac[i-1] * i %mod;
	inv[mx] = pow_mod(fac[mx], mod-2); for(int i = mx-1; i >= 0; i --) inv[i] = inv[i+1] *(i+1) % mod;
	int t, n, m, a, b, c, d;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
		if((a <= c && b >= d) || (a == 1 || d == 1)) {
			printf("0\n");
			continue;
		}
		if(a <= c && b < d) {
			swap(n,m);
			swap(a,d);
			swap(b,c);
		}
		ll ans = C(n+m-2,n-1);
		for(int i = a; i <= n; i ++) {
			ans = (ans-C(i+b-2,i-1)%mod*C(n-i+m-b-1,n-i))%mod;
		}
		for(int i = d; i <= m; i ++) {
			ans = (ans-C(c+i-2,i-1)%mod*C(n-c+m-i-1,n-c-1))%mod;
		}
		cout << (ans%mod+mod)%mod << endl;
	}
	return 0;
}