#include <stdio.h>
#include <iostream>
using namespace std;
const int N = 110;
const int INF = 1e6;
int g[N][N];
int main(){
    int n, m;
    while(~scanf("%d %d",&n,&m)&&n&&m){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(i == j) g[i][j] = 0;
                else{
                    g[i][j] = g[j][i] = INF;
                }
            }
        }
        for(int i = 1; i <= m; i ++){
            int u, v, w;
            scanf("%d %d %d",&v,&u,&w);
            g[v][u] = g[u][v] = w;
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                for(int k = 1; k <= n; k ++){
                    if(g[i][j] > g[i][k] + g[k][j]){
                        g[j][i] = g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }
        cout << g[1][n] << endl;
    }
    return 0;
}
