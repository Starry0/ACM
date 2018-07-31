#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
int t, n, ans1;
std::vector<int> vs[N];
bool vis[N];
void dfs(int u, int flag) {
	if(flag) ans1 ^= a[u];
	vis[u] = 1;
	for(auto t : vs[u]) {
		if(!vis[u]) dfs(t, 1-flag);
	}
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		int ans = 0;
		for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), ans ^= a[i], vs[i].clear();
		for(int i = 1; i < n; i ++) {
			int u, v;
			scanf("%d%d", &u, &v);
			vs[u].push_back(v);
			vs[v].push_back(u);
		}
		memset(vis, 0, sizeof(vis));
		dfs(1, 0);
		if((ans^ans1) == ans1) printf("D\n");
		else printf("Q\n");
	}
	return 0;
}