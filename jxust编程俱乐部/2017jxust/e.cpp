#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#define INF 0x3f3f3f3f
const int N = 1e5;
int vv[550], uu[550];
using namespace std;
struct Nod {
    int to, cap, rev;
};
vector<Nod> G[N];
bool vis[N];
void add_edge(int from, int to, int cap) {
    G[from].push_back((Nod){to,cap,(int)G[to].size()});
    G[to].push_back((Nod){from,0,(int)G[from].size()-1});
}
int dfs(int v, int t, int f) {
    if(v == t) return f;
    vis[v] = true;
    for(int i = 0; i < G[v].size(); i ++) {
        Nod &e = G[v][i];
        if(!vis[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f,e.cap));
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t){
    int flow = 0;
    while(1) {
        memset(vis,0,sizeof(vis));
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
    }
}
int main() {
	std::ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i ++) {
		int u, v;
		cin >> u >> v;
		uu[u] = 1;
		vv[v] = 1;
		add_edge(u, v+550, 1);
	}
	for(int i = 0; i < 510; i ++) {
		if(uu[i]) {
			add_edge(1997,i,1);
		}
		if(vv[i]) {
			add_edge(i+550, 2007, 1);
		}
	}
	printf("%d\n",max_flow(1997,2007));
	return 0;
}