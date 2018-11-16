#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e4+10;
int b[N], n, dp[N][2];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> b[i];
	for(int i = 2; i <= n; i ++) {
		dp[i][1] = max(dp[i-1][0]+b[i]-1,dp[i-1][1]+abs(b[i]-b[i-1]));
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]+b[i-1]-1);
	}
	printf("%d\n",max(dp[n][0],dp[n][1]));
	return 0;
}