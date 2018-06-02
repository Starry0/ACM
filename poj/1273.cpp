/*
Ford-Fullkerson 算法
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 210;
int n, m, u, v, w;
bool vis[N];
struct Nod{
    int to, cap, rev;
};
vector<Nod> vs[N];
void add_edge(int from, int to, int cap) {
    vs[from].push_back((Nod){to, cap, (int)vs[to].size()});
    vs[to].push_back((Nod){from, 0, (int)vs[from].size() - 1});
}
int dfs(int v, int t, int f) {
    if(v == t) return f;
    vis[v] = true;
    for(int i = 0; i < vs[v].size(); i ++) {
        Nod &e = vs[v][i];
        if(!vis[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                vs[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t) {
    int flow = 0;
    while(true) {
        memset(vis, 0, sizeof(vis));
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
    }
}
int main() {
    cin >> m >> n;
    for(int i = 1; i <= m; i ++) {
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, 0);
    }
    printf("%d\n",max_flow(1, n));
    return 0;
}
