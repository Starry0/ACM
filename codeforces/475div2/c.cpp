#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
const int mod = 1e9+9;
char str[N];
ll n, a, b, k, ans;
ll pow_mod(ll x, ll n){  
    ll ans=1;  
    while(n>0){  
        if(n&1)ans=ans*x%mod;  
        x=x*x%mod;  
        n>>=1;  
    }  
    return ans;  
}
int main() {
	cin >> n >> a >> b >> k;
	cin >> str;
	for(int i = 0; i < k; i ++) {
		if(str[i] == '-') {
			ans = (ans - pow_mod(a,n-i) * pow_mod(b, i)%mod+mod)%mod;
		} else {
			ans = (ans + pow_mod(a,n-i) * pow_mod(b, i)%mod)%mod;
		}
	}
	ll t = pow_mod(b, k) % mod * pow_mod(a, k*(mod-2))%mod;
	if(t == 1) {
		ans = ans * ((n+1)/k) % mod;
	} else {
		ans = ans * (1 - pow_mod(t, (n+1)/k))% mod * pow_mod(1 - t, mod-2) % mod;
	}
	cout << ans << endl;
	return 0;
}