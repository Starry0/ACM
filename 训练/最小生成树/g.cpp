#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
#define Inf 0x3f3f3f3f
const int N = 110;
int n, m;
double xx[550][2], cost[N][N], mincost[N], pre[11000], k;
bool vis[N];
priority_queue<double> que;
void prim(){
    k = 0;
    for(int i = 1; i <= n; i++){
        mincost[i] = Inf;
        vis[i] = false;
    }
    mincost[1] = 0;
    double res = 0;
    while(true){
        int v = -1;
        for(int i = 1; i <= n; i ++){
            if(!vis[i] && (v == -1 || mincost[i] < mincost[v])){
                v = i;
            }
        }
        if(v == -1) break;
        vis[v] = true;
        res = mincost[v];
        cout << res << endl;
        que.push(res);
        for(int i = 1; i <= n; i ++){
            mincost[i] = min(mincost[i], cost[v][i]);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        while(que.size()){
            que.pop();
        }
        memset(pre,0,sizeof(pre));
        memset(cost,Inf,sizeof(cost));
        for(int i = 1; i <= n; i++){
            scanf("%lf%lf",&xx[i][0],&xx[i][1]);
        }
        for(int i = 1; i <= n; i ++){
            for(int j = i+1; j <= n; j ++){
                double d = sqrt((xx[i][0]-xx[j][0])*(xx[i][0]-xx[j][0])+(xx[i][1]-xx[j][1])*(xx[i][1]-xx[j][1]));
                cost[i][j] = cost[j][i] = d;
            }
        }
        int res = 0;
        for(int i = 0, len = que.size(); i < len; i ++){
            double a = que.top();
            cout << a << endl;
            que.pop();
            res += a;
        }
        printf("%.2lf\n",res);
    }
    return 0;
}
