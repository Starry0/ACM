/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 55;
int G[N][N], vis[N], d[N];
int n, m;
int prim() {
    for(int i = 1; i <= n; i ++) vis[i] = 0, d[i] = INF;
    d[1] = 0;
    int res = 0;
    while(true) {
        int v = -1;
        for(int i = 1; i <= n; i ++) {
            if(!vis[i] && (v == -1 || d[v] > d[i])) v = i;
        }
        if(v == -1) break;
        vis[v] = 1;
        res += d[v];
        for(int i = 1; i <= n; i ++)
            d[i] = min(d[i], G[i][v]);
    }
    return res;
}
int main() {
    while(scanf("%d",&n)&&n) {
        scanf("%d",&m);
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                G[i][j] = (i==j ? 0: INF);
            }
        }
        for(int i = 1; i <= m; i ++) {
            int u, v, w;
            scanf("%d %d %d",&v, &u, &w);
            if(G[u][v] > w) {
                G[u][v] = G[v][u] = w;
            }
        }
        // for(int i = 1; i <= n; i ++) {
        //     for(int j = 1; j <= n; j ++)
        //         printf("%d ",G[i][j]);
        //     printf("\n");
        // }
        printf("%d\n",prim());
    }
    return 0;
}
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 55;
struct Nod {
    int u, v, cost;
}nod[N*N];
int fa[N];
bool cmp(const Nod &a, const Nod &b) {
    return a.cost < b.cost;
}
int find(int x) {
    return fa[x] = (fa[x] == x ? x: find(fa[x]));
}
int main() {
    int n, m;
    while(scanf("%d",&n)&&n) {
        scanf("%d",&m);
        int cnt = 1;
        for(int i = 1; i < N; i ++) fa[i] = i;
        for(int i = 1; i <= m; i ++) {
            int u, v, w;
            cin >> u >> v >> w;
            nod[cnt].u = u;
            nod[cnt].v = v;
            nod[cnt++].cost = w;
            nod[cnt].u = v;
            nod[cnt].v = u;
            nod[cnt++].cost = w;
        }
        sort(nod+1, nod+1+cnt, cmp);
        int res = 0;
        for(int i = 1; i < cnt; i ++) {
            int x = find(nod[i].u), y = find(nod[i].v);
            if(x != y) {
                fa[x] = y;
                res += nod[i].cost;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
