#include <iostream>
#include <stdio.h>
using namespace std;
int n, m;
int v[25],w[25];
int dp[25][30000];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) cin >> v[i] >> w[i];
	for(int i = 1; i <= m; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(v[i] <= j) {
				dp[i][j] = max(dp[i-1][j-v[i]]+w[i]*v[i],dp[i-1][j]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[m][n] << endl;
	return 0;
}