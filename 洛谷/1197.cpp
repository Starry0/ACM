#include <bits/stdc++.h>
using namespace std;
const int N = 4e5+10;
std::vector<int> vs[N];
int fa[N], p[N], cnt[N];
bool vis[N];
int find(int x) {
	return fa[x] = (fa[x] == x ? x: find(fa[x]));
}
int main() {
	int n, m, u, v, k;
	cin >> n >> m;
	for(int i = 0; i < n; i ++) fa[i] = i;
	for(int i = 0; i < m; i ++) {
		scanf("%d%d", &u, &v);
		vs[u].push_back(v);
		vs[v].push_back(u);
	}
	cin >> k;
	for(int i = 1; i <= k; i ++) {
		scanf("%d", &p[i]);
		vis[p[i]] = 1;
	}
	for(int i = 0; i < n; i ++) {
		if(!vis[i]) {
			for(auto v : vs[i]) {
				if(!vis[v]) fa[find(i)] = find(v);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i ++) if(!vis[i] && find(i) == i) ans++;
	cnt[0] = ans;
	for(int i = k; i >= 1; i --) {
		ans++;
		for(auto v : vs[p[i]]) {
			if(vis[v]) continue;
			if(find(v) != p[i]) {
				ans--;
				fa[find(v)] = find(p[i]);
			}
		}
		vis[p[i]] = 0;
		cnt[k-i+1] = ans;
	}
	for(int i = k; i >= 0; i --) printf("%d\n",cnt[i]);
	return 0;
}
