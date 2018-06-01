/*
网络流之最大流  未优化
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 220;
int n, m;
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
int main() {
    while(scanf("%d %d",&n, &m) != EOF) {
        for(int i = 0; i < n; i ++) {
            int u, v, w;
            scanf("%d %d %d",&u, &v, &w);
            add_edge(u, v, w);
        }
        printf("%d\n",max_flow(1,m));
        for(int i = 0; i <= m; i ++) G[i].clear();
    }
    return 0;
}