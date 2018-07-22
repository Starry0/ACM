#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3+10;
typedef pair<int,int> P;
vector<P> vs[N];
int d[N];
void dfs(int v) {
	for(auto p : vs[v]) {
		int u = p.first, w = p.second;
		if(d[u] < d[v] + w) {
			d[u] = d[v] + w;
			dfs(u);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		vs[v].push_back(P(u,w));
	}
	for(int i = 1; i <= n; i ++) {
		dfs(i);
	}
	int MAX = 0;
	for(int i = 1; i <= n; i ++) MAX = max(MAX, d[i]);
	printf("%d\n",MAX);
	return 0;
}