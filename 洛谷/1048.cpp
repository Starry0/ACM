#include <iostream>
#include <stdio.h>
using namespace std;
int T, m;
int dp[110][1010], t[110], p[110];
int main() {
	cin >> T >> m;
	for(int i = 1; i <= m; i ++) cin >> t[i] >> p[i];
	for(int i = 1; i <= m; i ++) {
		for(int j = 0; j <= T; j ++) {
			if(j >= t[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-t[i]]+p[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	printf("%d\n",dp[m][T]);
	return 0;
}