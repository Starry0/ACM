#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 300010;
ll a[N], sum[N], dp[N], n;
map<ll, ll> mp;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) cin >> sum[i], sum[i] += sum[i-1];
	for(int i = 1; i <= n; i ++) {
		if(!mp.count(a[i])) mp[a[i]] = INF;
		dp[i] = max(dp[i-1], sum[i] - mp[a[i]]);
		mp[a[i]] = min(mp[a[i]], sum[i-1]-dp[i-1]); 
	}
	cout << dp[n] << endl;
	return 0;
}