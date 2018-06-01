#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
const int mod = 1000000007;
const int M = 20010;
vector<int> vs[M], H[M];
bool vis[M];
int val[M], F[M], ans, cnt[M];
void init() {
	vis[0] = vis[1] = true;
	for(int i = 2; i <= 100; i ++) {
		if(!vis[i]) {
			for(int j = i*i; j <= 10000; j += i) vis[j] = true;
		}
	}
	for(int i = 4; i <= 10000; ++ i) {
		if(vis[i]) {
			for(int j = 4; j <= i; ++ j) {
				if(vis[j] && i%j == 0) H[i].push_back(j);
			}
		}
	}
}
void dfs(int u) {
	for(int i = 0; i < H[val[u]].size(); i ++) {
		F[u] -= cnt[H[val[u]][i]];
	}
	cnt[val[u]]++;
	for(int i = 0; i < vs[u].size(); i ++) {
		if(!vis[vs[u][i]]) {
			vis[vs[u][i]] = 1;
			dfs(vs[u][i]);
		}
	}
	for(int i = 0; i < H[val[u]].size(); i ++) {
		F[u] += cnt[H[val[u]][i]];
	}
	ans += 1LL*F[u]*u;
	ans %= mod;
}
int main() {
	init();
	//printf("%d\n",H[10].size());
	int t, n, p;
	cin >> t;
	while(t--) {
		memset(vis,0,sizeof(vis));
		memset(F,0,sizeof(F));
		memset(cnt,0,sizeof(cnt));
		for(int i = 0; i <= M; i ++) vs[i].clear();
		ans = 0;
		cin >> n >> p;
		for(int i = 0; i < n-1; i ++) {
			int u, v;
			cin >> u >> v;
			vs[u].push_back(v);
			vs[v].push_back(u);
		}
		for(int i = 1; i <= n; i ++) cin >> val[i];
		vis[p] = 1;
		dfs(p);
		cout << ans << endl;
	}
	return 0;
}
