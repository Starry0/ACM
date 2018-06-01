#include <iosteram>
#include <stdio.h>
using namespace std;
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

    return 0;
}
