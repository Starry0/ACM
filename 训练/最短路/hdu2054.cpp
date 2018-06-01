#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 110;
const int INF = 1e6;
int g[N][N], dist[N], n, m;
bool vis[N];

void dijistra(int x){
    int pos = x;
    for(int i = 1; i <= n; i ++){
        dist[i] = g[i][pos];
    }
    vis[pos] = true;
    for(int i = 1; i <= n; i ++){
        int mins = INF;
        for(int j = 1; j <= n; j ++){
            if(!vis[j] && dist[j] < mins){
                pos = j;
                mins = dist[j];
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
    while(cin>>n>>m){
        if(n == 0 && m == 0)break;
        memset(g,INF,sizeof(g));
        memset(vis,false,sizeof(vis));
        for(int i = 1; i <= N; i ++) g[i][i] = 0;
        for(int i = 1; i <= m; i ++){
            int v, s, w;
            scanf("%d %d %d",&v,&s,&w);
            g[v][s] = g[s][v] = w;
        }
        dijistra(1);
        cout << dist[n] << endl;
    }
    return 0;
}
