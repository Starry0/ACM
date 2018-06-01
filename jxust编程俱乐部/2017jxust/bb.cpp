#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
ll get(ll l, ll r) {
	ll q = 2*mod;
	return (l+1+r)%q*((r-l)%q)%q/2;
}
int main() {
	ll n, m, tmp;
	cin >> n >> m;
	ll ans = (n%mod)*(m%mod)%mod; 
	m = min(n, m);
	for(tmp = 1; tmp <= m && tmp*tmp <= n; ++tmp) {
		ans = (ans - n/tmp *tmp %mod)%mod;
	}
	for(ll i = n/tmp; i >= n/m; -- i) {
		ll l = n/(i+1), r = min(n/i, m);
		ans = (ans - get(l,r)*i)%mod;
	}
	cout << (ans+mod)%mod << endl;
	return 0;
}