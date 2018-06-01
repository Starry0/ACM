#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 110;
const int INF = 1e8;
int g[N][N], dist[N][N], n, pre[N][N], c[N];
bool vis[N];

void floyd(){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            dist[i][j] = g[i][j];
            pre[i][j] = j;       // pre[i][j]表示点i到j经过的第一个点
        }
    }
    for(int k = 1; k <= n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                int d = dist[i][k] + dist[k][j] + c[k];
                if(d < dist[i][j]){
                    dist[i][j] = d;
                    pre[i][j] = pre[i][k];
                }
                else if(d == dist[i][j]){
                    if(pre[i][j] > pre[i][k]){
                        pre[i][j] = pre[i][k];
                    }
                }
            }
        }
    }
}
int main(){
    while(~scanf("%d",&n)&&n){
        int tmp, a, b;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                scanf("%d",&g[i][j]);
                if(g[i][j] < 0) g[i][j] = INF;
            }
        }
        for(int i = 1; i <= n; i ++) scanf("%d",&c[i]);
        while(~scanf("%d %d",&a,&b)){
            if(a == -1 && b == -1) break;
            floyd();
            printf("From %d to %d :\n",a,b);
            printf("Path: %d",a);
            int k = a;
            while(k!=b){
                printf("-->%d",pre[k][b]);
                k = pre[k][b];
            }
            printf("\n");
            printf("Total cost : %d\n",dist[a][b]);
            printf("\n");
        }
    }
    return 0;
}
