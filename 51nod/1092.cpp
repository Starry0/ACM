#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char str[N];
int dp[N][N];
int main() {
	cin >> str+1;
	int n = strlen(str+1);
	for(int len = 2; len <= n; len ++) {
		for(int l = 1; l <= n - len + 1; l ++) {
			int r = l + len - 1;
			if(str[l] != str[r]) dp[l][r] = min(dp[l][r-1]+1, dp[l+1][r]+1);
			else dp[l][r] = dp[l+1][r-1];
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}