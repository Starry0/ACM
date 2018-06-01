#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1e3+10;
const int INF = 1e7;
int g[N][N], s[N], d[N], dist[N], T, S, D;
bool vis[N];
void init(){
    for(int i = 1; i <= 1001; i ++){
        for(int j = 1; j <= 1001; j ++){
            if(i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }
}
void dijistra(int x, int n){
    int pos = x;
    for(int i = 1; i <= n; i ++){
        dist[i] = g[i][pos];
        vis[i] = false;
    }
    vis[pos] = true;
    for(int i = 1; i <= n; i ++){
        int minn = INF;
        for(int j = 1; j <= n; j ++){
            if(!vis[j] && minn > dist[j]){
                minn = dist[j];
                pos = j;
            }
        }
        vis[pos] = true;
        for(int j = 1; j <= n; j ++){
            if(!vis[j] && dist[j] > dist[pos] + g[pos][j]){
                dist[j] = dist[pos] + g[pos][j];
            }
        }
    }
}
int main(){
    while(scanf("%d %d %d",&T,&S,&D)!=EOF){
        init();
        int maxn = -1;
        for(int i = 1; i <= T; i ++){
            int a, b, tim;
            scanf("%d %d %d",&a,&b,&tim);
            g[a][b] = g[b][a] = min(tim,g[a][b]);
            maxn = max(maxn,max(a,b));
        }
        for(int i = 1; i <= S; i ++){
            scanf("%d",&s[i]);
        }
        for(int i = 1; i <= D; i ++){
            scanf("%d",&d[i]);
        }
        int res = INF;
        for(int i = 1; i <= S; i ++){
            //memset(vis,false,sizeof(vis));
            dijistra(s[i],maxn);
            for(int j = 1; j <= D; j ++){
                res = min(res,dist[d[j]]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
