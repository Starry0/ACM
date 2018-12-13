#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int dp[N][2];
int main() {
	int n, m, x;
	cin >> n >> m;
	int last = 0;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		x %= m;
		last = 1-last;
		for()
	}
	return 0;
}