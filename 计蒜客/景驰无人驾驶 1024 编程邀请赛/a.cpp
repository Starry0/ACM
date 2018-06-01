/*#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int t, n, m1, m2, l;
const int N = 110;
struct Nod {
	int to, w, flag;
};
vector<Nod> G[N];
int vis[N];
int d[N];
typedef pair<int, int> P;
void init() {
	for(int i = 0; i < N; i ++) {
		d[i] = INF;
		G[i].clear();
		vis[i] = 0;
	}
}
void dij() {
	priority_queue<P, vector<P>, greater<P> > que;
	d[1] = 0;
	que.push(P(0,1));
	while(!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		for(int i = 0; i < G[v].size(); i ++) {
			Nod e = G[v][i];
			printf("%d --> %d\n",v,e.to);
			if(e.w + d[v] > l) continue;
			if(e.w + d[v] == d[e.to]) {
				if(e.flag == 1) {
					if(vis[v] < vis[e.to]) vis[e.to] = vis[v];
				} else {
					if(vis[v] + e.w < vis[e.to]) 
						vis[e.to] = vis[v] + e.w;
				}
			} else if (e.w + d[v] < d[e.to]){
				d[e.to] = d[v] + e.w;
				que.push(P(d[e.to], e.to));
				if(e.flag == 2) vis[e.to] = vis[v] + e.w;
			}
		}
	}
}
int main() {
	cin >> t;
	while(t--) {
		init();
		int u, v, c;
		scanf("%d %d %d %d", &n, &m1, &m2, &l);
		for(int i = 0; i < m1; i ++) {
			scanf("%d %d", &u, &v);
			G[u].push_back((Nod){v,1,1});
			G[v].push_back((Nod){u,1,1});
		}
		for(int i = 0; i < m2; i ++) {
			scanf("%d %d %d", &u, &v, &c);
			G[u].push_back((Nod){v,c,2});
			G[v].push_back((Nod){u,c,2});
		}
		dij();
		for(int i = 1; i <= n; i ++) printf("%d ,", d[i]);
		printf("\n");
		if(d[n] <= l) printf("%d\n", vis[n]);
		else printf("-1\n");
	}
	return 0;
}*/

/*
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
bool vis[N][N];
vector<int> vs[N];
int t, m1, m2, n, l;
int head[N], dp[N][N], cnt;
struct Nod {
	int to, w, nex;
}e[N*N];
void add(int u, int v, int w) {
	e[cnt].to = v, e[cnt].w = w;
	e[cnt].nex = head[u], head[u] = cnt++;
}
struct node {
	int u, id, w;
	bool operator < (const node & a) const {
		return w > a.w;
	}
};
void init() {
	memset(head, -1, sizeof(head));
	cnt = 0;
	for(int i = 0; i < N; i ++) vs[i].clear();
	
}
void dij() {
	priority_queue<node> que;
	dp[1][0] = 0;
	memset(dp, INF, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	node p, q;
	p.u = 1, p.id = 0, p.w = 0;
	que.push(p);
	while(!que.empty()) {
		p = que.top(); que.pop();
		if(vis[p.u][p.id]) continue;
		vis[p.u][p.id] = 1;
		
		for(int i = head[p.u]; ~i; i = e[i].nex) {
			int v = e[i].to;
			if(dp[v][p.id] > p.w + e[i].w) {
				dp[v][p.id] = p.w + e[i].w;
				q.u = v,q.id = p.id, q.w = dp[v][p.id];
				que.push(q);
			}
		}
		if(p.id == m1) continue;
		for(int i = 0; i < (int)vs[p.u].size(); ++ i) {
			int v = vs[p.u][i];
			if(dp[v][p.id + 1] > p.w + 1) {
				dp[v][p.id+1 + 1] = p.w + 1;
				q.u = v, q.id = p.id+1,q.w = dp[v][p.id+1];
				que.push(q);
			}
		}
	}
}
int main() {
	cin >> t;
	while(t--) {
		init();
		int x, y, c;
		scanf("%d %d %d %d", &n, &m1, &m2, &l);
		for(int i = 0; i < m1; i ++) {
			cin >> x >> y;
			vs[x].push_back(y);
			vs[y].push_back(x);
		}
		for(int i = 0; i < m2; i ++) {
			scanf("%d %d %d", &x, &y, &c);
			add(x, y, c);
			add(y, x, c);
		}
		dij();
		int ans = INF;
		for(int i = 0; i <= m1; i ++) {
			if(dp[n][i] <= l) ans = min(ans, dp[n][i]-i);
		}
		printf("%d\n", ans==INF?-1:ans);
	}
	return 0;	
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1LL*100000000000000100;
const int N = 110;
ll n, m1, m2, t, l;
ll vis[N], g[N][N], dp[N], dis[N];
typedef pair<int, int> P;
vector<P> vs[N];
void dij() {
	memset(vis, 0, sizeof(vis));
	queue<int> que;
	que.push(1); vis[1] = 1; dp[1] = dis[1] = 0;
	while(!que.empty()) {
		int u = que.front();
		vis[u] = 1;
		que.pop();
		for(int i = 0; i < vs[u].size(); i ++) {
			int v = vs[u][i].first, w = vs[u][i].second;
			if(dp[v] > dp[u] + w && dis[u] + w <= l) {
				dp[v] = dp[u] + 1LL*w;
				dis[v] = dis[u] + 1LL*w;
				if(!vis[v]) {
					que.push(v);
					vis[v] = 1;
				}
			}
		}
		for(int i = 1; i <= n; i ++) {
			if(g[u][i]) {
				if(dp[i] > dp[u] && dis[u] + 1LL <= l) {
					dp[i] = dp[u];
					dis[i] = dis[u] + 1LL;
					if(!vis[i]) {
						que.push(i);
						vis[i] = 1;
					}
				}
			}
		}
	}
	if(dp[n] <= l && dis[n] <= l) printf("%lld\n",dp[n]);
	else printf("-1\n");
}
int main() {
	cout << INF << endl;
	cin >> t;
	while(t--) {
		memset(g, 0, sizeof(g));
		for(int i = 0; i < N; i ++) {
			dp[i] = dis[i] = INF;
			vs[i].clear();
		}
		cin >> n >> m1 >> m2 >> l;
		int u, v, c;
		for(int i = 0; i < m1; i ++) {
			cin >> u >> v;
			g[u][v] = g[v][u] = 1;
		}
		for(int i = 0; i < m2; i ++) {
			cin >> u >> v >> c;
			vs[u].push_back(P(v,c));
			vs[v].push_back(P(u,c));
		}
		dij();
	}
	return 0;
}
*/
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
int t, n, m1, m2, l;
int g[N][N], vis[N], dp[N], dis[N];
typedef pair<int, int> P;
vector<P> vs[N];
void init() {
	for(int i = 0; i <= n; i ++) {
		vs[i].clear();
		dp[i] = dis[i] = INF;
	}
	memset(g, 0, sizeof(g));
	memset(vis, 0, sizeof(vis));
}
void dij() {
	queue<int> que;
	que.push(1); vis[1] = 1;
	dp[1] = dis[1] = 0;
	while(!que.empty()) {
		int u = que.front();que.pop();
		vis[u] = 0;
		for(int i = 0; i < vs[u].size(); i ++) {
			int v = vs[u][i].first, w = vs[u][i].second;
			if(dp[v] > dp[u] + w && dis[u] + w <= l) {
				dp[v] = dp[u] + w;
				dis[v] = dis[u] + w;
				if(!vis[v]) {
					vis[v] = 1;
					que.push(v);
				}
			}
		}
		for(int i = 1; i <= n; i ++) {
			if(g[u][i]) {
				if(dp[i] > dp[u] && dis[u] + 1 <= l) {
					dp[i] = dp[u];
					dis[i] = dis[u] + 1;
					if(!vis[i]) {
						vis[i] = 1;
						que.push(i);
					}
				}
			}
		}
	}
	if(dp[n] <= l && dis[n] <= l) cout << dp[n] << endl;
	else cout << -1 << endl;
}
int main() {
	cin >> t;
	while(t--) {
		int u, v, w;
		cin >> n >> m1 >> m2 >> l;
		init();
		for(int i = 1; i <= m1; i ++) {
			cin >> u >> v;
			g[u][v] = g[v][u] = 1;
		}
		for(int i = 1; i <= m2; i ++) {
			cin >> u >> v >> w;
			vs[u].push_back(P(v, w));
			vs[v].push_back(P(u, w));
		}
		dij();
	}
	return 0;
}