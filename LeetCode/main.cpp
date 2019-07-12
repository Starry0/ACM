#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> vs[N];
bool vis[N];
int ans = 0, n, m, x, y;
void dfs(int v, int f, int cnt) {
	if(vs[v].size() == 1 && v != 1) {
		ans++;
		return;
	}
	if(cnt >= m) return;
	for(auto u : vs[v]) {
		if(u == f) continue;
		if(vis[u]) dfs(u, v, cnt+1);
		else dfs(u, v, cnt);
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i ++) cin >> vis[i];
	for(int i = 0; i < n-1; i ++) {
		cin >> x >> y;
		vs[x].push_back(y);
		vs[y].push_back(x);
	}
	dfs(1, -1, 0);
	cout << ans << endl;
	return 0;
}