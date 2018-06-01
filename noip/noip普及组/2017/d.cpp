#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 500010;
ll f[N], sum[N], dp[N];
ll max(ll x, ll y) {
	return x > y ? x: y;
}
int main() {
	ll n, d, k, ans = 0;
	cin >> n >> d >> k;
	for(int i = 1; i <= n; i ++) {
		cin >> f[i] >> sum[i];
		if(sum[i] > 0)
			ans += sum[i];
	}
	if(ans < k) return 0*printf("-1\n");
	ll l = 0, r = 1e9+10;
	while(l <= r) {
		ll mid = (l+r) >> 1LL;
		memset(dp, -INF, sizeof(dp));
		ans = 0;
		dp[0] = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = i-1; j >= 0; j --) {
				if(f[i]-f[j] <= d + mid && f[i] - f[j] >= d - mid) {
					dp[i] = max(dp[i], (dp[j] + sum[i]));
				} 
			}
			ans = max(ans, dp[i]);
		}
		if(ans >= k) r = mid-1;
		else l = mid+1;
	}
	printf("%lld\n",l);
	return 0;
}