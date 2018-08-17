#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const ll mod = 998244353;
const int N = 2e5+10;
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
	int mx = N;
	fac[0] = 1;for(int i = 1; i <= mx; i ++) fac[i] = fac[i-1] * i %mod;
	inv[mx] = pow_mod(fac[mx], mod-2); for(int i = mx-1; i >= 0; i --) inv[i] = inv[i+1] *(i+1) % mod;
	int t, n, m, k;
	cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		ll ans = 0;
		for(int i = 0; i*n <= k; i ++) {
			if(i&1) ans = (ans - C(m,i)*C(m-1+k-n*i, m-1)%mod+mod) % mod;
			else ans = (ans + C(m,i)*C(m-1+k-n*i, m-1)%mod+mod) % mod;
		}
		cout << ans%mod << endl;
	}
	return 0;
}