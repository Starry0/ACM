#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 100010;
int dp[N], t, m, x, y;
int main() {
	cin >> t >> m;
	for(int i = 0; i < m; i ++) {
		cin >> x >> y;
		for(int j = x; j <= t; j ++) {
			dp[j] = max(dp[j],dp[j-x]+y);
		}
	}
	cout << dp[t] << endl;
	return 0;
}