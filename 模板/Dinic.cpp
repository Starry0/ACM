/*
网络流之最大流  优化
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 100010;
int T, d[MAX], start, tend;
struct node {
    int to, cap, next;
}edge[MAX<<1];
int head[MAX];
bool vis[MAX];
int cnt;
void add_edge(int start, int to, int cap) {
    edge[cnt].to = to;
    edge[cnt].cap = cap;
    edge[cnt].next = head[start];
    head[start] = cnt++;
}
bool bfs() {
    memset(d, -1, sizeof(d));
    int Q[MAX<<1];
    int Thead = 0, Ttail = 0;
    Q[Ttail++] = start;
    d[start] = 0;
    while(Thead < Ttail) {
        int x = Q[Thead];
        if(x == tend) return true;
        for(int i = head[x]; i != -1; i = edge[i].next) {
            int tmp = edge[i].to;
            if(d[tmp] == -1 && edge[i].cap > 0) {
                d[tmp] = d[x] + 1;
                Q[Ttail++] = tmp;
            }
        }
        Thead++;
    }
    return false;
}
int dfs(int x, int cap) {
    if(x == tend) return cap;
    int flow = 0, f;
    for(int i = head[x]; i != -1; i = edge[i].next) {
        int tmp = edge[i].to;
        if(d[tmp] == d[x] + 1 && edge[i].cap) {
            f = dfs(tmp,min(cap-flow,edge[i].cap));
            edge[i].cap -= f;
            edge[i^1].cap += f;
            flow += f;
            if(flow == cap)break;
        }
    }
    if(!flow) d[x] = -2;
    return flow;
}
int max_flow() {
    int flow = 0, f;
    while(bfs()) {
        while((f = dfs(start,INF)) > 0) flow += f;
    }
    return flow;
}
int main() {
    int n, m;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        cnt = 0;
        memset(head, -1, sizeof(head));
        int x, y, u, v, w;
        int tmax = -INF, tmin = INF;
        start = tend = 1;
        for(int i = 1; i <= n; i ++) {
            scanf("%d %d",&x,&y);
            if(x >= tmax) tmax = x, tend = i;
            if(x <= tmin) tmin = x, start = i;
        }
        while(m--) {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        int ans = max_flow();
        printf("%d\n",ans);
    }
    return 0;
}