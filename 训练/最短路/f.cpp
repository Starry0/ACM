#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1010;
const int INF = 1e8;
int g[N][N], dist[N], dp[N], n, m;
bool vis[N];

void dijistra(int x){
    memset(vis,false,sizeof(vis));
    int pos = x;
    for(int i = 1; i <= n; i ++){
        dist[i] = g[i][pos];
    }
    vis[pos] = true;
    for(int i = 1; i <= n; i ++){
        int minn = INF;
        for(int j = 1; j <= n; j ++){
            if(!vis[j] && minn > dist[j]){
                pos = j;
                minn = dist[j];
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

int dfs(int x){
    int sum = 0;
    if(dp[x] != -1) return dp[x];
    if(x == 2) return 1;
    for(int i = 1; i <= n; i ++){
        if(g[i][x] != INF && dist[i] < dist[x]){
            sum += dfs(i);
        }
    }
    dp[x] = sum;
    return sum;
}

int main(){
    while(~scanf("%d",&n)&&n){
        scanf("%d",&m);
        for(int i = 1; i <= n; i ++){
            dp[i] = -1;
            for(int j = 1; j <= n; j ++){
                g[i][j] = (i==j) ? 0 : INF;
            }
        }
        for(int i = 1; i <= m; i ++){
            int u, v, w;
            scanf("%d %d %d",&u,&v,&w);
            if(w < g[u][v])
                g[u][v] = g[v][u] = w;
        }
        dijistra(2);
        // for(int i = 1; i <= n; i ++){
        //     cout << dist[i] << endl;
        // }
        printf("%d\n",dfs(1));
    }
    return 0;
}
