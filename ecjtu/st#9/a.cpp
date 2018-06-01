#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
const int MAX = 55;
const int INF = 1<<30;
const int dir[4][2]{{-1,0},{0,1},{1,0},{0,-1}};

struct Nod{
    int x;
    int y;
    int t;
    int d;
    bool operator < (const Nod &a) const{
        return t > a.t;
    }
};
int g[MAX][MAX], n, m, mark[MAX][MAX][4];
int bfs(int bx, int by, int ex, int ey, int f) {
    priority_queue<Nod> que;
    Nod nod;
    mark[bx][by][f] = 0;
    que.push((Nod){bx,by,0,f});
    while(!que.empty()) {
        nod = que.top();
        que.pop();
        int x = nod.x, y = nod.y;
        if(x == ex && y == ey) return nod.t;
        int d = nod.d;
        if(mark[x][y][(d+1)%4] == -1 || mark[x][y][(d+1)%4] > nod.t + 1){
            mark[x][y][(d+1)%4] = nod.t+1;
            que.push((Nod){x,y,nod.t+1,(d+1)%4});
        }
        if(mark[x][y][(d-1+4)%4] == -1 || mark[x][y][(d-1+4)%4] > nod.t + 1){
            mark[x][y][(d-1+4)%4] = nod.t + 1;
            que.push((Nod){x,y,nod.t+1,(d-1+4)%4});
        }
        int nx = x, ny = y;
        for(int i = 1; i <= 3; i ++) {
            nx += dir[d][0];
            ny += dir[d][1];
            if(nx <= 0 || nx >= m || ny <= 0 || ny >= n)break;
            if(g[nx][ny] == 1 || g[nx-1][ny] == 1 || g[nx][ny-1] == 1 || g[nx-1][ny-1] == 1) break;
            ///上行必须要用四个判断，因为机器人是在线上的，而障碍物是块，比如在(7,2)这个点，判断这个点
            //是否可以走，就要判断(7,2),(7,1),(6,1),(6,2)这个四个点有没有块
            if(mark[nx][ny][d] == -1 || mark[nx][ny][d] > nod.t+1){
                mark[nx][ny][d] = nod.t+1;
                que.push((Nod){nx,ny,nod.t+1,d});
            }
        }
    }
    return -1;
}
int main() {
    int bx, by, ex, ey, d, ans;
    char str[20];
    while(scanf("%d%d",&m,&n)&&(n+m)) {
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                scanf("%d",&g[i][j]);
            }
        }
        scanf("%d %d %d %d %s",&bx,&by,&ex,&ey,str);
        if(str[0] == 'n') d = 0;
        else if(str[0] == 'e') d = 1;
        else if(str[0] == 's') d = 2;
        else if(str[0] == 'w') d = 3;
        memset(mark,-1,sizeof(mark));
        ans = bfs(bx,by,ex,ey,d);
        printf("%d\n",ans);
    }
    return 0;
}
