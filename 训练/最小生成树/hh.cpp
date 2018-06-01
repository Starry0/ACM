#include <iostream>
#include <stdio.h>
#define Inf 0x3f3f3f3f;
using namespace std;
const int N = 770;

int edg[N][N], n, m, k, x[N], y[N], mincost[N], pre[N];

void prime(){
    for(int i = 1; i <= N; i++){
        mincost[i] = edg[1][i];
        pre[i] = 1;
    }
    mincost[1] = -1;
    for(int i = 1; i < n; i ++){
        int minn = Inf;
        for(int j = 1; j <= n; j ++) {
            if(mincost[j] != -1 && mincost[j] < minn){
                minn = mincost[j];
                k = j;
            }
        }
        if(mincost[k] != 0) printf("%d %d\n",pre[k], k);
        mincost[k] = -1;
        for(int j = 1; j <= n; j ++){
            if(edg[j][k] < mincost[j]){
                mincost[j] = edg[j][k];
                pre[j] = k;
            }
        }
    }
}
int main(){
    while(~scanf("%d",&n)){
        for(int i = 1; i <= n; i++){
            scanf("%d%d",&x[i],&y[i]);
            for(int j = 1; j < i; j++){
                edg[i][j] = edg[j][i] = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            }
            edg[i][i] = Inf;
        }
        scanf("%d",&m);
        for(int i = 1; i <= m; i ++){
            int a, b;
            scanf("%d%d",&a,&b);
            edg[a][b] = edg[b][a] = 0;
        }
        prime();
    }
    return 0;
}
