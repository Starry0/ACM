#include <iostream>
#include <stdio.h>
using namespace std;
int n, m;
int a[1010];
int dp[101][10001];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= m; j ++) {
			if(j >= a[i]) dp[i][j] = dp[i-1][j-a[i]]+dp[i-1][j];
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}

/*
#include <iostream>
#include <stdio.h>
using namespace std;
int n, m;
int a[1010];
int dp[10001];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	dp[0] = 1;
	for(int i = 1; i <= n; i ++) {
		for(int j = m; j >= a[i]; j --) {
			dp[j] += dp[j-a[i]];
		}
	}
	cout << dp[m] << endl;
	return 0;
}

*/