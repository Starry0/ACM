#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
const ll mod = 1e9+7;
ll dp[N][3];

int main() {
	ll n, l, r;
	cin >> n >> l >> r;
	l--;
	for(int i = 1; i <= 3; i ++) {
		ll ans1 = (l-i+3)/3;
		ll ans2 = (r-i+3)/3;
		dp[1][i%3] = ans2-ans1;
	}
	for(int i = 2; i <= n; i ++) {
		for(int j = 0; j < 3; j ++) {
			for(int k = 0; k < 3; k ++) {
				if(dp[i-1][k])
				dp[i][(k+j)%3] += (dp[i-1][k] * dp[1][j])%mod;
				dp[i][(k+j)%3] %= mod;
			}
		}
	}
	cout << dp[n][0] << endl;
	return 0;
}

