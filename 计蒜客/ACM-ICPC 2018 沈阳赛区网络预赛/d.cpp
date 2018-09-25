#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e3+10;
const int M = 1e4+10;
int n, m, s, e, k, t;
typedef pair<int,int> P;
vector<P> vs[N], rvs[N];
int dist[N];
struct Nod{
	int v, w;
	bool operator < (const Nod &a) const{
		return w+dist[v] > a.w+dist[a.v];
	}
};
void dij() {
	priority_queue<P, vector<P>, greater<P> >que;
	memset(dist, INF, sizeof(dist));
	dist[e] = 0;
	que.push(P(0,e));
	while(que.size()) {
		P p = que.top(); que.pop();
		if(dist[p.second] < p.first) continue;
		for(auto q:rvs[p.second]) {
			int v = q.first, w = q.second;
			if(dist[v] > dist[p.second] + w) {
				dist[v] = dist[p.second] + w;
				que.push(P(dist[v],v));
			}
		}
	}
}
int Astart() {
	priority_queue<Nod> que;
	que.push((Nod){s,0});
	int ans = 0;
	while(que.size()) {
		Nod ee = que.top(); que.pop();
		if(ee.v == e) ans++;
		if(ans == k) return ee.w;
		for(auto E:vs[ee.v]) {
			int u = E.first, w = E.second;
			que.push((Nod){u,ee.w+w});
		}
	}
	return -1;
}
int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		scanf("%d%d%d%d",&s,&e,&k,&t);
		for(int i = 1; i <= n; i ++) vs[i].clear(), rvs[i].clear();
		for(int i = 1; i <= m; i ++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			vs[u].push_back(P(v,w));
			rvs[v].push_back(P(u,w));
		}
		dij();
		if(dist[s] == INF) printf("Whitesnake!\n");
		else {
			if(s == e) k++;
			int ans = Astart();
			if(ans <= t && ans != -1) printf("yareyaredawa\n");
			else printf("Whitesnake!\n");
		}
	}
	return 0;
}