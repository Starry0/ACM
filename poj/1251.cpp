/*
#include <iostream>
#include <string.h>
#include <stdio.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 30;
int G[N][N], d[N], vis[N], n;
int prim() {
    for(int i = 1; i <= n; i ++) d[i] = INF, vis[i] = 0;
    d[1] = 0;
    int res = 0;
    while(true) {
        int v = -1;
        for(int i = 1; i <= n; i ++) {
            if(!vis[i] && (v==-1 || d[i] < d[v])) v = i;
        }
        if(v == -1) break;
        vis[v] = 1;
        res += d[v];
        for(int i = 1; i <= n; i ++)
            d[i] = min(d[i],G[i][v]);
    }
    return res;
}
int main() {
    while(scanf("%d",&n)&&n) {
        for(int i = 1; i < N; i ++){
            for(int j = 1; j < N; j ++)
                G[i][j] = (i==j? 0: INF);
        }
        char c,c1;
        int num, m;
        for(int i = 1; i < n; i ++) {
            cin>>c>>m;
            for(int j = 1; j <= m; j ++) {
                cin>>c1>>num;
                G[c-'A'+1][c1-'A'+1] = G[c1-'A'+1][c-'A'+1] = num;
            }
        }
        printf("%d\n",prim());
    }
    return 0;
}
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 30;
struct Nod {
    int u, v, cost;
}nod[N*N];
int fa[N];
int find(int x) {
    return fa[x] = (fa[x] == x ? fa[x]: find(fa[x]));
}
bool cmp(const Nod &a, const Nod &b) {
    return a.cost < b.cost;
}
int main() {
    int n;
    while(scanf("%d",&n)&&n) {
        for(int i = 1; i < N; i ++) fa[i] = i;
        char c, c1;
        int m, num, cnt = 1;
        for(int i = 1; i < n; i ++) {
            cin >> c >> m;
            for(int j = 1; j <= m; j ++) {
                cin >> c1 >> num;
                nod[cnt].u = c - 'A' + 1;
                nod[cnt].v = c1 - 'A' + 1;
                nod[cnt++].cost = num;
                nod[cnt].v = c - 'A' + 1;
                nod[cnt].u = c1 - 'A' + 1;
                nod[cnt++].cost = num;
            }
        }
        sort(nod+1, nod+1+cnt, cmp);
        int res = 0;
        for(int i = 1; i < cnt; i ++) {
            int x = find(nod[i].u), y = find(nod[i].v);
            if(x != y) {
                res += nod[i].cost;
                if(x < y) fa[y] = x;
                else fa[x] = y;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
