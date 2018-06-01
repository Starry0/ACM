#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
const int N = 550;
int d[N], dist[N][N], price[N];
int main(){
    int n,m,s,e;
    memset(dist,Inf,sizeof(dist));
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(int i = 1; i <= N; i ++) scanf("%d",&price[i]),dist[i][i] = 0;
    for(int i = 0; i < m; i ++) {
        int v, u, w;
        scanf("%d%d%d",&v,&u,&w);
        
    }
    return 0;
}
