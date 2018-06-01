//这题用kruskal算法会超时，而用prim算法就不会。
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int inf = 1<<30;
int n, m;
int dist[1010][1010],d[1010],vis[1010];
int prim(){
    for(int i = 1; i <= n; i ++){
        d[i] = dist[i][1];
        vis[i] = false;
    }
    d[1] = 0;
    int res = 0;
    while(true){
        int v = -1;
        for(int i = 1; i <= n; i ++){
            if(!vis[i] && (v==-1 || d[i] < d[v]))
                v =i;
        }
        if(v == -1) break;
        vis[v] = 1;
        res += d[v];
        for(int i = 1; i <= n; i ++){
            d[i] = min(d[i],dist[i][v]);
        }
    }
    return res;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= n; j ++){
            dist[i][j] = (i==j)?0:inf;
        }
    }
    for(int i = 0; i < m; i ++){
        int s, e, w;
        scanf("%d%d%d",&s,&e,&w);
        if(dist[s][e] > w){
            dist[s][e] = dist[e][s] = w;
        }
    }
    printf("%d\n",prim());
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Nod{
    int s,e,w;
}e[1010];
bool cmp(Nod a, Nod b){
    return a.w < b.w;
}
int fa[1010];
int n,m;
int find(int x){
    if(fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
    //return fa[x] = (fa[x]==x?x:find(fa[x]));
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x < y) fa[y] = x;
    else fa[x] = y;
}
int kruskal(){
    for(int i = 1; i <= n; i ++) fa[i] = i;
    int res = 0;
    for(int i = 1; i <= m; i ++){
        Nod es = e[i];
        if(find(es.s) != find(es.e)){
            unite(es.s,es.e);
            res += es.w;
        }
    }
    return res;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= m; i ++){
        scanf("%d%d%d",&e[i].s,&e[i].e,&e[i].w);
    }
    sort(e+1,e+1+m,cmp);
    printf("%d\n",kruskal());
    return 0;
}
