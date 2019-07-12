#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 5050;
typedef pair<int,int> P;
vector<P> vs[N];
int u,n, m, v, w, s, t, k;
int d[N];
struct Nod{
	int v, w;
	bool operator < (const Nod &a) const {
		return d[v] + w > d[a.v] + a.w;
	}
};
void dij() {
	memset(d, INF, sizeof(d));
	priority_queue<P, vector<P>, greater<P> > que;
	d[t] = 0;
	que.push(P(0, t));
	while(que.size()) {
		P p = que.top(); que.pop();
		int u = p.second;
		if(d[u] < p.first) continue;
		for(int i = 0; i < vs[u].size(); ++ i) {
			P e = vs[u][i];
			int v = e.first, w = e.second;
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				que.push(P(d[v], v));
			}
		}
	}
}
int AStart() {
	priority_queue<Nod> que;
	que.push((Nod){s, 0});
	int ans = 0;
	while(que.size()) {
		Nod p = que.top(); que.pop();
		if(p.v == t) ans++;
		if(ans == k) return p.w;
		for(int i = 0; i < vs[p.v].size(); ++ i) {
			que.push((Nod){vs[p.v][i].first,vs[p.v][i].second+p.w});
		}
	}
	return -1;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d%d",&v,&u,&w);
		vs[v].push_back(P(u,w));
		vs[u].push_back(P(v,w));
	}
	s = 1, t = n, k = 2;
	dij();
	printf("%d\n",AStart());
	return 0;
}