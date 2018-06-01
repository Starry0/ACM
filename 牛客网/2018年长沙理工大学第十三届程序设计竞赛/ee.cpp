#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 200010;
typedef pair<int,int> P;
struct Nod {
	int to, cost;
};
vector<Nod> vs[N];
int d[N];
void dij(int s) {
	priority_queue<P, vector<P>, greater<P> > que;
	d[s] = 0;
	que.push(P(0,s));
	while(que.size()) {
		P p = que.top(); que.pop();
		int v = p.second;
		//printf("dsa\n");
		if(d[v] < p.first) continue;
		//cout << vs[v].size() << endl;
		for(int i = 0; i < vs[v].size(); i ++) {
			Nod e = vs[v][i];
			//cout << e.to << ' ' << e.cost << endl;
			if(d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i <= n; i ++) d[i] = INF;
	for(int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		Nod e;
		e.to = v; e.cost = w;
		vs[u].push_back(e);
		Nod ee;
		ee.to = u; ee.cost = w;
		vs[v].push_back(ee);
	}
	dij(1);
	//for(int i = 1; i <= n; i ++) cout << d[i] << ' ';
	//cout << endl;
	if(d[n] == INF) printf("qwb baka\n");
	else cout << d[n] << endl;
	return 0;
}