#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 2e3+10;
int n, cost[maxn][maxn], mincost[maxn];
bool vis[maxn];
string s[maxn];

int prim(){
    for(int i = 1; i <= n; i ++){
        mincost[i] = cost[1][i];
        vis[i] = false;
    }
    mincost[1] = 0;
    int res = 0;
    while(true){
        int v = -1;
        for(int i = 1; i <= n; i ++){
            if(!vis[i] && (v == -1 || mincost[i] < mincost[v]))
                v = i;
        }
        if(v == -1) break;
        vis[v] = true;
        res += mincost[v];
        for(int i = 1; i <= n; i ++){
            mincost[i] = min(mincost[i], cost[i][v]);
        }
    }
    return res;
}
int main(){
    while(~scanf("%d",&n)&&n){
        char ss[10];
        for(int i = 1; i <= n; i ++){
            scanf("%s",ss);
            s[i] = ss;
        }
        memset(cost, 10,sizeof(cost));
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                int ans = 0;
                for(int k = 0; k < 7; k ++){
                    if(s[i][k] != s[j][k])
                    ans++;
                }
                cost[i][j] = cost[j][i] = ans;
            }
        }
        printf("The highest possible quality is 1/%d.\n",prim());
    }
    return 0;
}
