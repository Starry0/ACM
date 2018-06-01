#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1e4+10;
const int INF = 1e8;
int g[N][N], cost[N][N], dist[N], pre[N], n, m;
bool vis[N];

void dijistra(int x){
    int pos = x;
    for(int i = 1; i <= n; i ++){
        dist[i] = g[i][pos];
        pre[i] = cost[i][pos];
    }
    vis[pos] = true;
    for(int i = 1; i <= n; i ++){
        int mins = INF, minp = INF;
        for(int j = 1; j <= n; j ++){
            if(!vis[j] && dist[j] < mins){
                mins = dist[j];
                pos = j;
                minp = pre[j];
            }else if(!vis[j] && dist[j] == mins){
                if(pre[j] < minp){
                    pos = j;
                    pre[j] = minp;
                }
            }
        }
        vis[pos] = true;
        for(int j = 1; j <= n; j ++){
            if(!vis[pos]){
                if(dist[j] > dist[pos] + g[pos][j]){
                    dist[j] = dist[pos] + g[pos][j];
                    pre[j] = pre[pos] + cost[pos][j];
                }else if(dist[j] == dist[pos] + g[pos][j]){
                    if(pre[j] > pre[pos] + cost[pos][j]){
                        pre[j] = pre[pos] + cost[pos][j];
                    }
                }
            }
        }
    }
}

int main(){
    while(~scanf("%d %d",&n,&m)&&n&&m){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(i == j){
                    g[i][j] = cost[i][j] = 0;
                }
                else{
                    g[i][j] = g[j][i] = INF;
                    cost[i][j] = cost[j][i] = INF;
                }
            }
        }
        memset(vis,false,sizeof(vis));
        for(int i = 1; i <= m; i ++){
            int a, b, d, p;
            scanf("%d %d %d %d",&a,&b,&d,&p);
            if(g[a][b] > d){
                g[a][b] = g[b][a] = d;
                cost[a][b] = cost[b][a] = p;
            }else if(d == g[a][b]){
                if(p < cost[a][b]){
                    cost[a][b] = cost[b][a] = p;
                }
            }
        }
        int s, t;
        cin >> s >> t;
        dijistra(s);
        cout << dist[s] << ' ' << pre[t] << endl;
    }
    return 0;
}
