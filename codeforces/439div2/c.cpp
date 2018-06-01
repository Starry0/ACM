#include <bits/stdc++.h>
#define ll long long
const ll mod = 998244353;
using namespace std;
const int N = 5010;
ll f[N][N];
int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	for(ll i = 1; i <= 5000; i ++) f[i][1] = f[1][i] = i+1;
	for(ll i = 2; i <= 5000; i ++) {
		for(ll j = 2; j <= 5000; j ++) {
			f[i][j] = f[i-1][j] + f[i-1][j-1]*j%mod;
			f[i][j] %= mod;
		}
	}
	ll ans = (f[a][b]*f[b][c]%mod)*f[c][a]%mod;
	printf("%lld\n",ans);
	return 0;
}