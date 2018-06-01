#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
const ll INF = 1LL<<60;
struct Nod {
	ll to, cost;
};
vector<Nod> G[N];
ll dist[N];
typedef pair<ll, ll> P;
void dij(ll x) {
	priority_queue<P, vector<P>, greater<P> > que;
	for(int i = 0; i < N; i ++) dist[i] = INF;
	dist[x] = 0;
	que.push(P(0, x));
	while(!que.empty()) {
		P p = que.top();
		que.pop();
		ll v = p.second;
		if(dist[v] < p.first) continue;
		for(ll i = 0; i < G[v].size(); i ++) {
			Nod e = G[v][i];
			if(dist[e.to] > dist[v] + e.cost) {
				dist[e.to] = dist[v] + e.cost;
				que.push(P(dist[e.to], e.to));
			}
		}
	}
}
int main() {
	int n, q, cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n-1; i ++) {
		ll v, u, w;
		scanf("%lld %lld %lld", &v, &u, &w);
		G[v].push_back((Nod){u,w});
		G[u].push_back((Nod){v,w});
	}
 	ll k;
 	scanf("%d %lld", &q, &k);
 	dij(k);
 	while(q--) {
 		ll x, y;
 		scanf("%lld %lld", &x, &y);
 		printf("%lld\n",dist[x] + dist[y]);
 	}
	return 0;
}