#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
const ll INF = 1e17;
const int M = 2e5+10;
ll cnt, k, n, m, t, v, u, ww;
ll dist[N][30], w[M];
int fir[N], nex[M], to[M];
struct Nod{
	ll x, k, d;
	bool operator<(const Nod &a)const{          
		return d > a.d;
	}
};
void add(ll u, ll v, ll ww) {
	nex[++ cnt] = fir[u];
	fir[u] = cnt;
	to[cnt] = v;
	w[cnt] = ww;
}
ll dijstra(int n) {
	memset(dist,127,sizeof(dist));
	priority_queue<Nod> que;
	que.push((Nod){1,0,0});
	dist[1][0] = 0;
	while(que.size()) {
		Nod e = que.top(); que.pop();
		if(e.d != dist[e.x][e.k]) continue;
		if(e.x == n) return e.d;
		for(int i = fir[e.x]; i; i = nex[i]) {
			if(dist[to[i]][e.k] > dist[e.x][e.k] + w[i]) {
				dist[to[i]][e.k] = dist[e.x][e.k] + w[i];
				que.push((Nod){to[i], e.k, dist[to[i]][e.k]});
			}
			if(e.k < k && dist[to[i]][e.k+1] > dist[e.x][e.k]) {
				dist[to[i]][e.k+1] = dist[e.x][e.k];
				que.push((Nod){to[i],e.k+1,dist[to[i]][e.k+1]});
			}
		}
	}
}
void init() {
	cnt = 0;
	memset(nex,0,sizeof(nex));
	memset(fir,0,sizeof(fir));
	memset(to,0,sizeof(to));
}
int main() {
	scanf("%lld", &t);
	while(t--) {
		init();
		scanf("%lld%lld%lld", &n, &m, &k);
		for(int i = 1; i <= m; i ++) {
			scanf("%lld%lld%lld", &v, &u, &ww);
			add(v,u,ww);
		}
		printf("%lld\n",dijstra(n));
	}
	return 0;
}