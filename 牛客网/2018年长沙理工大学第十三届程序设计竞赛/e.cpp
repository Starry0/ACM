#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
const int N = 200010;
const ll INF = 1e17;
ll n, m;
ll d[N];
struct edge{
    ll to, cost;
};
vector<edge> g[N];
typedef pair<ll,ll> P;
void dijistra(ll s){
    priority_queue<P,vector<P>,greater<P> > que;
    d[1] = 0;
    que.push(P(0,s));
    while(!que.empty()){
        P p = que.top();que.pop();
        ll v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < g[v].size(); i ++){
            edge e = g[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main() {
	cin >> n >> m;
	for(int i = 0; i <= n; i ++) d[i] = INF;
	for(int i = 0; i < m; i ++) {
		ll u, v, w;
		cin >> u >> v >> w;
		edge e;
		e.to = v;e.cost=w;
		g[u].push_back(e);
		edge ee;
		ee.to = u;e.cost=w;
		g[v].push_back(ee);
	}
	dijistra(1);
	if(d[n] == INF) printf("qwb baka\n");
	else printf("%d\n",d[n]);
	return 0;
}