#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int g[N], vis[N][10];
int dfs(int x) {
	if(x < 10) return x;
	int ans = 1, tmp = x;
	while(tmp) {
		if(tmp%10) ans *= tmp%10;
		tmp /= 10;
	}
	g[x] = ans>=10?dfs(ans):ans;
	return g[x];
}
int main() {
	for(int i = 1; i <= N; i ++) {
		if(!g[i]) g[i] = dfs(i);
	}
	for(int i = 1; i <= N; i ++) {
		for(int j = 1; j < 10; j ++) {
			vis[i][j] = vis[i-1][j] + (j==g[i]);
		}
	}
	int q, l, r, k;
	cin >> q;
	while(q--) {
		cin >> l >> r >> k;
		cout << vis[r][k] - vis[l-1][k] << endl;
	}
	return 0;
}
