/*
最小生成数
*/

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
