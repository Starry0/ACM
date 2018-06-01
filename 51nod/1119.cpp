#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
ll pow_mod(ll x, ll n){  
    ll res=1;  
    while(n>0){  
        if(n&1)res=res*x%mod;  
        x=x*x%mod;  
        n>>=1;  
    }  
    return res;  
}
ll AA(ll n) {
	ll ans = 1;
	for(ll i = 1; i <= n; i ++) ans = ans*i%mod;
	return ans;
}
int main() {
	ll n, m;
	cin >> m >> n;
	ll x = n + m -2, y = n - 1;
	ll ans = AA(x) % mod;
	ans = ans*pow_mod(AA(y), mod-2)%mod;
	ans = ans*pow_mod(AA(x-y), mod-2)%mod;
	printf("%lld\n",ans);
	return 0;
}