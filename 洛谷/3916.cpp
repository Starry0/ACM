#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> vs[N];
bool vis[N];
int a[N];
void dfs(int v, int MAX) {
	vis[v] = 1;
 	for(int i = 0; i < vs[v].size(); i ++) {
 		if(!vis[vs[v][i]]) {
 			a[vs[v][i]] = max(MAX, a[vs[v][i]]);
 			dfs(vs[v][i], MAX);
 		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) a[i] = i;
	for(int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		vs[v].push_back(u);
	}
	for(int i = n; i >= 1; i --) {
		if(!vis[i]) dfs(i,i);
	}
	for(int i = 1; i <= n; i ++) printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}