#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

const int MAX = 2010;
int T, n, m, s, t;
struct Nod {
    int to, cap, rev;
};
vector<Nod> G[MAX];
int level[MAX], iter[MAX];
void add_edge(int from, int to, int cap) {
    G[from].push_back((Nod){to,cap,(int)G[to].size()});
    G[to].push_back((Nod){from,0,(int)G[from].size()-1});
}
void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int i = 0; i < G[v].size(); i ++) {
            Nod &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size(); i ++) {
        Nod &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
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
int max_flow(int s, int t) {
    int flow = 0;
    while(1) {
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
}
int main(){
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &m);
		scanf("%d %d", &s, &t);
		for(int i = 0; i < m; i ++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			add_edge(u, v, w);
		}
		printf("%d\n",max_flow(s, t));
		for(int i = 0; i < MAX; i ++) G[i].clear();
	}
	return 0;
}