#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
const int mod = 1e9+7;
ll dp[N][N*10];
int main() {
	dp[0][0] = 1;
	int n;cin >> n;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= i*9; j ++) {
			for(int k = 0; k <= 9; k ++) {
				if(j>=k) dp[i][j] = (dp[i][j]+dp[i-1][j-k])%mod;
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i <= 9*n; i ++) {
		ans = (ans+(dp[n][i]-dp[n-1][i])*dp[n][i])%mod;
	}
	cout << ans << endl;
	return 0;
}