/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
int G[N][N], vis[N], d[N];
int n;
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
        res += d[v];
        vis[v] = 1;
        for(int i = 1; i <= n; i ++)
            d[i] = min(d[i], G[i][v]);
    }
    return res;
}
int main() {
    while(scanf("%d",&n)&&n) {
        for(int i = 1; i < N; i ++) {
            for(int j = 1; j < N; j ++) {
                G[i][j] = (i==j ? 0: INF);
            }
        }
        for(int i = 1; i <= n*(n-1)/2; i ++) {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            if(G[u][v] > w) {
                G[u][v] = G[v][u] = w;
            }
        }
        printf("%d\n",prim());
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct edge{
    int u, v, w;
}e[N*N];
bool cmp(edge &a, edge &b) {
    return a.w < b.w;
}
int fa[N];
int find(int x) {
    return fa[x] == x ? x: find(fa[x]);
}
void unite(int x, int y) {
    fa[find(x)] = find(y);
}
int main() {
    int n;
    while(scanf("%d", &n), n){
        for(int i = 1; i <= n; i ++) fa[i] = i;
        for(int i = 0; i < n*(n-1)/2; i ++) {
            scanf("%d %d %d",&e[i].u, &e[i].v, &e[i].w);
        }
        sort(e,e+n*(n-1)/2,cmp);
        int ans = 0;
        for(int i = 0; i < n*(n-1)/2; i ++) {
            if(find(e[i].v) != find(e[i].u)) {
                ans += e[i].w;
                unite(e[i].v,e[i].u);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
