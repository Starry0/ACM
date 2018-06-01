#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 210;
const int INF = 0xffffff;
int g[N][N], dist[N], n, m;
bool vis[N];

void dijistra(int x){
    int pos = x;
    for(int i = 0; i < n; i ++){
        dist[i] = g[i][pos];
    }
    vis[pos] = true;
    for(int i = 0; i < n; i ++){
        int mins = INF;
        for(int j = 0; j < n; j ++){
            if(!vis[j] && dist[j] < mins){
                pos = j;
                mins = dist[j];
            }
        }
        vis[pos] = true;
        for(int j = 0; j < n; j ++){
            if(!vis[j] && dist[j] > dist[pos] + g[pos][j]){
                dist[j] = dist[pos] + g[pos][j];
            }
        }
    }
}
int main(){
    while(cin>>n>>m){
        //memset(g,INF,sizeof(g));
        for(int i = 0; i < N; i ++){
            for(int j = 0; j < N; j ++){
                g[i][j] = (i==j)?0:INF;
            }
        }
        memset(vis,false,sizeof(vis));
        for(int i = 0; i <= N; i ++) g[i][i] = 0;
        for(int i = 1; i <= m; i ++){
            int v, s, w;
            scanf("%d %d %d",&v,&s,&w);
            if(w < g[v][s]){
                g[v][s] = g[s][v] = w;
            }
        }
        int s,e;
        cin >> s >> e;
        dijistra(s);
        int ans = dist[e];
        //cout << ans << endl;
        if(ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
