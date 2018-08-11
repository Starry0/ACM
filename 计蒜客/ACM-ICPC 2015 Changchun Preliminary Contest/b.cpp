#include <bits/stdc++.h>
#define ll unsigned	 long long
using namespace std;
const int N = 10010;
int n, m, t, u, v, p, cnt;
ll a[N];
std::vector<int> vs[N], vv;
int vis[N], vis1[N];

bool ok(int x) {
	int ans = 0;
	for(auto u : vs[x]) {
		if(!vis[u]) ans++;
	}
	return ans < 2;
}

void dfs(int v) {
	vis[v] = 1;
	for(auto u : vs[v]) {
		if(!vis[u]&&ok(u)) dfs(u);
	}
}
void dfs1(int v) {
	vis1[v] = 1;
	for(auto u : vs[v]) {
		if(!vis[u]&&!vis1[u]) {
			vv.push_back(u);
			dfs1(u);
		}
	}
}

int main() {
	cin >> t;
	while(t--) {
		memset(vis, 0, sizeof(vis));
		memset(vis1, 0, sizeof(vis1));
		cin >> p >> m;
		for(int i = 1; i <= p; i ++) scanf("%lld", &a[i]);
		for(int i = 0; i < m; i ++) {
			scanf("%d%d", &v, &u);
			vs[v].push_back(u);
			vs[u].push_back(v);
		}
		for(int i = 1; i <= p; i ++) {
			if(!vis[i]&&ok(i)) dfs(i);
		}
		// for(int i = 1; i <= p; i ++) printf("%d ",vis[i]);printf("\n");
		for(int i = 1; i <= p; i ++) {
			if(!vis[i]&&!vis1[i]) {
				vv.clear();
				vv.push_back(i);
				dfs1(i);
				// printf("-=%d-=\n", vv.size());
				if(vv.size()%2 == 0) {
					for(int j = 0; j < vv.size(); j ++) vis1[vv[j]] = 2;
				}
			}
		}
		// for(int i = 1; i <= p; i ++) printf("%d ",vis1[i]);printf("\n");
		ll ans = 0;
		for(int i = 1; i <= p; i ++) if(vis1[i]==1) ans += a[i];
		printf("%lld\n",ans);
		for(int i = 1; i <= p; i ++) vs[i].clear();
	}
	return 0;
} 