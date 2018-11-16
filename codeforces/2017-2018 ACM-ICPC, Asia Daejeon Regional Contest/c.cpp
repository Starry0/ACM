#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1e5+10;
vector<int> vs[N];
int MAX, ans[N];
int dfs(int v) {
	if(ans[v]!=0) return ans[v];
	int cnt = 0;
	for(auto u : vs[v]) {
		if(vs[u].size() > vs[v].size()) {
			cnt = max(cnt, dfs(u));
		}
	}
	ans[v] = cnt+1;
	return cnt+1;
}
int main() {
	int n, m, v, u;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		cin >> v >> u;
		vs[v].push_back(u);
		vs[u].push_back(v);
	}
	for(int i = 0; i < n; i ++) {
		dfs(i);
		MAX = max(MAX, ans[i]);
	}
	cout << MAX << endl;
	return 0;
}