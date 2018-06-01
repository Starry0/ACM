#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 550;
int co[MAX], dist[MAX], g[MAX][MAX],low[MAX];
int n, m, s, e;
bool vis[MAX];
void dijistra(){
    for(int i = 0; i < n; i ++){
        dist[i] = INF;
    }
    memset(vis,0,sizeof(vis));
	memset(low,0,sizeof(vis));
	dist[s] = 0;
	low[s] = co[s];
    for(int i = 1; i <= n; i ++){
        int mins = INF, MAx = 0, pos;
        for(int j = 0; j < n; j ++){
            if(!vis[j] && dist[j] < mins){
                pos = j;
                mins = dist[j];
				MAx = co[j];
            }
			if(!vis[j] && dist[j] == mins && MAx < low[j]){
				pos = j;
				MAx = low[j];
			}
        }
		if(mins == INF)break;
        vis[pos] = true;
        for(int j = 1; j <= n; j ++){
            if(!vis[j] && dist[j] > dist[pos] + g[pos][j]){
                dist[j] = dist[pos] + g[pos][j];
				low[j] = low[pos] + co[j];
            }
			if(!vis[j] && low[j] < low[pos] + co[j] && dist[j] == dist[pos]+g[pos][j]){
				low[j] = low[pos] + co[j];
			}
        }
    }
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&e);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++)
			g[i][j] = (i==j)?0:INF;
	}
	for(int i = 0; i < n; i ++) scanf("%d",&co[i]);
	for(int i = 0; i < m; i ++) {
		int u, v, w;
		scanf("%d%d%d",&u,&v,&w);
		if(g[u][v] > w) {
			g[u][v] = g[v][u] = w;
		}
	}
	dijistra();
	printf("%d %d\n",dist[e],low[e]);
	return 0;
}
