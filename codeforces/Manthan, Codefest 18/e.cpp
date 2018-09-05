#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
set<int> st[N], s;
int ans[N], x[N], y[N];
int n, m, k;
void dfs(int v) {
	if(st[v].size() >= k || !s.count(v)) return;
	s.erase(v);
	for(auto u:st[v]) {
		st[u].erase(v);
		if(s.count(u) && st[u].size() < k) {
			dfs(u);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d", &x[i], &y[i]);
		st[x[i]].insert(y[i]);
		st[y[i]].insert(x[i]);
	}
	for(int i = 1; i <= n; ++ i) s.insert(i);
	for(int i = 1; i <= n; i ++) {
		if(st[i].size() < k) {
			dfs(i);
		}
	}
	ans[m] = s.size();
	for(int i = m; i > 1; i --) {
		st[x[i]].erase(y[i]);
		st[y[i]].erase(x[i]);
		if(st[x[i]].size() < k) dfs(x[i]);
		if(st[y[i]].size() < k) dfs(y[i]);
		ans[i-1] = s.size();
	}
	for(int i = 1; i <= m; i ++) printf("%d\n",ans[i]);
	return 0;
}