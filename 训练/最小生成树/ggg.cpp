#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int N = 550;
const double Inf = 1000000;
int n, m, t, k;
double a[N][2], cost[N][N], sum[N], mincost[N];
bool vis[N];
void init(){
    memset(cost,Inf,sizeof(cost));
    memset(sum,0,sizeof(sum));
    memset(vis,false,sizeof(vis));
}
void prim(){
    k = 0;
    for(int i = 1; i <= n; i ++){
        mincost[i] = cost[1][i];
    }
    mincost[1] = 0;
    while(true){
        int v = -1;
        for(int i = 1; i <= n; i ++){
            if(!vis[i] && (v == -1 || mincost[i] < mincost[v]))
                v = i;
        }
        if(v == -1) break;
        vis[v] = true;
        sum[k++] = mincost[v];
        for(int i = 1; i <= n; i ++){
            mincost[i] = min(mincost[i], cost[i][v]);
        }
    }
}
int main(){
    cin >> t;
    while(t--){
        init();
        scanf("%d%d",&m,&n);
        for(int i = 1; i <= n; i ++) {
            scanf("%lf%lf",&a[i][0],&a[i][1]);
        }
        for(int i = 1; i <= n; i ++){
            for(int j = i+1; j <= n; j ++){
                double d = sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]));
                cost[i][j] = cost[j][i] = d;
            }
        }
        prim();
        sort(sum,sum+k);
        //for(int i = 0; i < k; i ++) cout << sum[i] << endl;
        printf("%.2lf\n",sum[k-m]);
    }
    return 0;
}
