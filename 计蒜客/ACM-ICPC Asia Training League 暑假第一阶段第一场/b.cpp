#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 10010;
typedef pair<int, int> P;
struct Nod{
	int to, w;
};
vector<Nod> vs[N];
int dist[N];

void bfs(int s) {
	priority_queue<P,vector<P>,greater<P> > que;
	dist[s] = 0;
	que.push(P(0, s));
	while(!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if(dist[v] < p.first) continue;
		for(int i = 0; i < vs[v].size(); i ++) {
			Nod e = vs[v][i];
			if(dist[e.to] > dist[v] + e.w) {
				dist[e.to] = dist[v] + e.w;
				que.push(P(dist[e.to], e.to));
			}
		}
	}
}
int main() {
	int t, n, d, c;
	scanf("%d", &t);
	while(t--) {
		memset(dist, INF, sizeof(dist));
		scanf("%d%d%d", &n, &d, &c);
		for(int i = 0; i < d; i ++) {
			int a, b, s;
			Nod e;
			scanf("%d%d%d", &a, &b, &s);
			e.to = a, e.w = s;
			vs[b].push_back(e);
		}
		bfs(c);
		int cnt = 0, MIN = 0;
		for(int i = 1; i <= n; i ++) {
			if(dist[i] != INF) {
				cnt++;
				MIN = max(MIN, dist[i]);
			}
		}
		for(int i = 1; i <= n; i ++) {
			vs[i].clear();
		}
		printf("%d %d\n",cnt,MIN);
	}
	return 0;
}