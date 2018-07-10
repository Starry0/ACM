#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int a[N], n, m, k;
int dp[N][2];
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		if(a[i] == m) k = i;
	}
	int ans = 1,cnt1 = 0, cnt2 = 0;
	int i = k-1;
	while(i > 0) {
		if(a[i] > m) {
			dp[i][0] = dp[i+1][0];
			dp[i][1] = dp[i+1][1] + 1;
		} else {
			dp[i][0] = dp[i+1][0] + 1;
			dp[i][1] = dp[i+1][1];
		}
	}
	i = k+1;
	while(i <= n) {
		if(a[i] > m) {
			dp[i][0] = dp[i+1][0];
			dp[i][1] = dp[i+1][1] + 1;
		} else {
			dp[i][0] = dp[i+1][0] + 1;
			dp[i][1] = dp[i+1][1];
		}
	}
	
	return 0;
}