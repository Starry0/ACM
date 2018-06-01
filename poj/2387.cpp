/*
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1010;
int G[N][N], vis[N], d[N];
int t, n;
void dijkstra() {
    for(int i = 1; i <= n; i ++) d[i] = INF, vis[i] = 0;
    d[1] = 0;
    while(true) {
        int v = -1;
        for(int i = 1; i <= n; i ++) {
            if(!vis[i] && (v == -1 || d[v] > d[i])) v = i;
        }
        if(v == -1) break;
        vis[v] = 1;
        for(int i = 1; i <= n; i ++)
        d[i] = min(d[i],d[v]+G[i][v]);
    }
}
int main() {
    while(scanf("%d%d",&t,&n) != EOF) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++)
            G[i][j] = (i==j ? 0: INF);
        }
        for(int i = 1; i <= t; i ++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if(G[u][v] > w) {
                G[u][v] = G[v][u] = w;
            }
        }
        dijkstra();
        printf("%d\n",d[n]);
    }
    return 0;
}
*/

#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2010;
struct edge {
    int to, cost;
};
vector<edge> G[N];
int d[N], t, n;
typedef pair<int,int> P;
void dijkstra() {
    priority_queue<P, vector<P>, greater<P> > que;
    for(int i = 1; i <= n; i ++) d[i] = INF;
    d[1] = 0;
    que.push(P(0,1));
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i ++) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
int main() {
    while(scanf("%d%d",&t,&n)!=EOF) {
        for(int i = 1; i <= t; i ++) {
            int u, v, w;
            scanf("%d %d %d",&u, &v, &w);
            G[u].push_back((edge){v,w});
            G[v].push_back((edge){u,w});
        }
        dijkstra();
        printf("%d\n",d[n]);
    }
    return 0;
}
