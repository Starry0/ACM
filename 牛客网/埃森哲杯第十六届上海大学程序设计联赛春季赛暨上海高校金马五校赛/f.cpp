#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
ll dp[61], n;
int main() {
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3; i <= 60; i ++) {
		dp[i] = dp[i-1]+dp[i-2];
	}
	for(int i = 1; i <= 60; i ++) {
		dp[i] = dp[i] + dp[i-1];
	}
	//cout << dp[60] << endl;
	int t;
	cin >> t;
	while(t--) {
		ll ans = 0;
		cin >> n;
		while(n) {
			for(int i = 0; i <= 60; i ++) {
				if((dp[i+1]+1) > n && n >= (dp[i]+1)) {
					ans += (1LL<<i);
				//	cout << ans << endl;
					n -= (dp[i]+1LL);
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}