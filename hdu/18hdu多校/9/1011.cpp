#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
const ll mod = 998244353;

ll POW(ll x, ll y) {
	ll ans = 1;
	while(y) {
		if(y&1) ans = ans*x%mod;
		x = x*x%mod;
		y >>= 1;
	}
	return ans;
}

int main() {
	ll t, a, b, c, d, n;
	cin >> t;
	while(t--) {
		cin >> a >> b >> c >> d;
		n = a+b+c+d;
		// ll ans1 = POW(2,c) + POW(2,b) - 1;
		ll ans1 = (POW(2,c)-1)*POW(2,a)+(POW(2,b)-1)*POW(2,a)+POW(2,a) % mod;
		ll cnt1 = (((d*POW(2,c))%mod)*POW(2,a))%mod + (((b*POW(2,a))%mod)*(POW(2,c)-1))%mod;
		// ans1 = (ans1 + b*(POW(2,c)-1)%mod + d*POW(2,c))*POW(2,a)%mod;
		printf("%lld\n",(ans1+cnt1)%mod);
	}
	return 0;
}