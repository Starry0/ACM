#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
vector<int> vs[N];
struct Nod{
	int a, b;
}e[N];
int vis1[N], vis[N];
void dfs(int v) {
	if(vis1[v] != 0) return;
	vis1[v] = 2;
	if(e[v].b == 2) dfs(e[v].a);
	else if(e[v].b == 1) {
		if(vis1[e[v].a] == 2) {
			vis[e[v].a] = 1;
			return;
		}
	}
	vis1[v] = 1;
}
void dfs1(int v) {
	vis[v] = 1;
	for(auto u:vs[v]) {
		if(vis[u] == 0) dfs1(u);
	}
}
int main() {
	int t, n, x;
	char s[20];
	scanf("%d", &t);
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i ++) {
			vs[i].clear();
			vis[i] = vis1[i] = 0;
		}
		for(int i = 1; i <= n; i ++) {
			scanf("%d%s",&x,s);
			e[i].a = x;
			if(s[0] == 'w') e[i].b = 1;
			else {
				e[i].b = 2;
				vs[x].push_back(i);
			}
		}
		for(int i = 1; i <= n; i ++) {
			if(vis1[i] == 0 && e[i].b == 2) dfs(i);
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++) if(vis[i]) dfs1(i);
		for(int i = 1; i <= n; i ++) if(vis[i]) ans++;
		// for(int i = 1; i <= n; i ++) printf("%d%c",vis[i]," \n"[i==n] );
		printf("0 %d\n",ans);
	}
	return 0;
}