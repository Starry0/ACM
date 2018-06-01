/*
网络流之最大流
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 1010;
struct Nod {
    int to, cap, rev;
};
vector<Nod> G[MAX];
bool vis[MAX];
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
    int t, n, m;
    scanf("%d",&t);
    for(int k = 1; k <= t; k ++) {
        scanf("%d %d",&n, &m);
        while(m--) {
            int u, v, w;
            scanf("%d %d %d",&u, &v, &w);
            add_edge(u,v,w);
        }
        printf("Case %d: %d\n",k,max_flow(1,n));
        for(int i = 1; i <= n; i ++) G[i].clear();
    }
    return 0;
}