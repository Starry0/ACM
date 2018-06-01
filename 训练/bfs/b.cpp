#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
char s[5], ss[5];
int gx, gy, sx, sy;
int dis[8][2] = {{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2}};
typedef pair<int, int> P;
int d[10][10];
int bfs(){
    queue<P> que;
    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            d[i][j] = 1e6;
        }
    }
    que.push(P(sx, sy));
    d[sx][sy] = 0;
    while(que.size()){
        P p = que.front();que.pop();
        if(p.first == gx && p.second == gy) return d[gx][gy];
        for(int i = 0; i < 8; i ++){
            int nx = p.first + dis[i][0], ny = p.second + dis[i][1];
            if(0 <= nx && nx < 8 && 0 <= ny && ny < 8 && d[nx][ny] == 1e6){
                d[nx][ny] = d[p.first][p.second] + 1;
                que.push(P(nx, ny));
            }
        }
    }
    return d[gx][gy];
}
int main(){
    while(cin>>s>>ss){
        sx = s[0] - 'a';
        sy = s[1] - '1';
        gx = ss[0] - 'a';
        gy = ss[1] - '1';
        int res = bfs();
        printf("To get from %s to %s takes %d knight moves.\n",s,ss,res);
    }
}
