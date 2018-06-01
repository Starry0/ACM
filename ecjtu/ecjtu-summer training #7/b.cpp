#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const int MAX = 1010;
const int INF = 0xffffff;
int g[MAX][MAX],ans,dist[MAX],n,m;
bool vis[MAX];
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
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0&&m==0)break;
		for(int i = 0; i <= n; i ++)
			for(int j = 0; j <= n; j ++)
				g[i][j] = (i==j)?0:INF;
		for(int i = 0; i < m; i ++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if(c < g[a][b]){
				g[a][b] = c;
				g[b][a] = c;
			}
		}
		ans = 0;
		dijistra(1);
		printf("%d\n",dist[n]);
		memset(g,0,sizeof(g));
		memset(vis,false,sizeof(vis));
		memset(dist,0,sizeof(dist));
	}
	return 0;
}
