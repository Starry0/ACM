//dp做法
#include <iostream>
#include <string.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int main() {
	int n, k;
	cin >> n >> k;
	int dp[2][k+10];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[i] %= k;
	}
	dp[0][a[1]] = 1;
	int last = 0;
	for(int i = 2; i <= n; i ++) {
		last = 1 - last;
		for(int j = 0; j < k; j ++) {
			if(dp[1-last][j]) 
				dp[last][(j+a[i])%k] = max(dp[1-last][(j+a[i])%k],dp[1-last][j]+1);
			else dp[last][(j+a[i])%k] = dp[1-last][(j+a[i])%k];
		}
	}
	cout << dp[last][0] << endl;
	return 0;
}