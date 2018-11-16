#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5+10;
int dp[N];
int main() {
	int n, m, x;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		if(i <= m) {
			continue;
		}
		for(int j = i-2*m; j <= i-m; j ++) {
			if(j < 0) continue;
			dp[i] = max(dp[i], dp[j]+x);
		}
	}
	int MAX = 0;
	for(int i = 1; i <= n; i ++) MAX = max(dp[i], MAX);
	cout << MAX << endl;
	return 0;
}