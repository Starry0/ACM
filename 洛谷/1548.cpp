#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= min(n,m); i ++) {
		ans1 += (m-i+1)*(n-i+1);
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(i == j) continue;
			ans2 += (n-i+1)*(m-j+1);
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}