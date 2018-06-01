#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1010;
char str[N];
int dp[N];
int main() {
	int n, d;
	cin >> n >> d >> str;
	for(int i = 0; i < N; i ++) dp[i] = INF;
	dp[0] = 0;
	for(int i = 0; i < n; i ++) {
		if(str[i] == '1') {
			for(int k = max(0,i-d); k < i; k ++)
				dp[i] = min(dp[i], dp[k]+1);
		}
	}
	printf("%d\n",dp[n-1]==INF?-1:dp[n-1]);
	return 0;
}