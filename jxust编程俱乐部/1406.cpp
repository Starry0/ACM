/*#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 310;
int g[N][N];
int main() {
	int t, a, b, m, u, v;
	cin >> t;
	while(t--) {
		cin >> a >> b >> m;
		for(int i = 1; i < N; i ++) {
			for(int j = 1; j < N; j ++) {
				g[i][j] = INF;
			}
		}
		for(int i = 0; i < m; i ++) {
			cin >> u >> v;
			g[u][v] = g[v][u] = 1;
		}
		for(int k = 1; k <= a+b; k ++) {
			for(int i = 1; i <= a+b; i ++) {
				for(int j = 1; j <= a+b; j ++) {
					g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		int ans = INF;
		for(int i = 1; i <= a; i ++) {
			ans = min(ans, g[i][a+b]);
		}
		if(ans == INF) printf("No\n");
		else printf("%d\n",ans);
	}
	return 0;
}*/

#include <bits/stdc++.h>
const int N = 20005;
using namespace std;
struct Nod {
	int x, ans;
	bool operator < (const Nod & a) const {
		return a.ans < ans;
	}
}q,p;
int vis[N];
vector<int> vs[N];
int main() {
	int t, a, b, k, u, v;
	cin >> t;
	while(t--) {
		bool flag = false;
		priority_queue<Nod> que;
		cin >> a >> b >> k;
		while(k--) {
			cin >> u >> v;
			vs[u].push_back(v);
			vs[v].push_back(u);
		}
		q.x = a+b; q.ans = 0;
		que.push(q);
		while(!que.empty()) {
			q = que.top();
			que.pop();
			for(int i = 0; i < vs[q.x].size(); i ++) {
				int x = vs[q.x][i];
				if(vis[x]) continue;
				vis[x] = true;
				if(x <= a) {
					printf("%d\n",q.ans+1);
					flag = true;
					break;
				} else {
					p.x = x; p.ans = q.ans+1;
					que.push(p);
				}
			}
			if(flag) break;
		}
		if(!flag) printf("No\n");
		for(int i = 0; i < 1010; i ++) vs[i].clear();
	}
}