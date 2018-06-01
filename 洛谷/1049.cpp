#include <iostream>
#include <stdio.h>
using namespace std;
int dp[33][20010];
int V, n, v[33];
int main() {
	cin >> V >> n;
	for(int i = 1; i <= n; i ++) cin >> v[i];
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= V; j ++) {
			if(j >= v[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]]+v[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << V - dp[n][V] << endl;
	return 0;
}