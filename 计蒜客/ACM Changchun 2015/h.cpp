#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2020;
int dp[N], a[N];
int main() {
	int t, n, x;
	cin >> t;
	while(t--) {
		cin >> n;
		memset(dp,-INF,sizeof(dp));
		for(int i = 0; i < n-1; i ++) cin >> a[i];
		int cnt = n-2;
		dp[0] = a[0]*n;
		for(int i = 1; i < n-1; i ++) a[i] -= a[0];
		for(int i = 1; i <= cnt; i ++) {
			for(int j = i; j <= cnt; j ++) {
				dp[j] = max(dp[j], dp[j-i]+a[i]);
			}
		}
		cout << dp[cnt] << endl;

	}
	return 0;
}