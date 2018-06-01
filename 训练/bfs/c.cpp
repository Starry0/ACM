#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int gx, gy, sx, sy, n;
int dis[8][2] = {{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2}};
typedef pair<int, int> P;
int d[500][500];
int bfs(){
    queue<P> que;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            d[i][j] = -1;
        }
    }
    que.push(P(sx, sy));
    d[sx][sy] = 0;
    while(que.size()){
        P p = que.front();que.pop();
        if(p.first == gx && p.second == gy) return d[gx][gy];
        for(int i = 0; i < 8; i ++){
            int nx = p.first + dis[i][0], ny = p.second + dis[i][1];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && d[nx][ny] == -1){
                d[nx][ny] = d[p.first][p.second] + 1;
                que.push(P(nx, ny));
            }
        }
    }
    return d[gx][gy];
}
int main(){
    int k;
    cin >> k;
    while(k--){
        scanf("%d%d%d%d%d",&n,&sx,&sy,&gx,&gy);
        int res = bfs();
        printf("%d\n",res);
    }
}
