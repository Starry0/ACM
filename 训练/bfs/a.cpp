#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
char s[5],ss[5];
int gx, gy, sx, sy;
int dis[8][2] = {{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2}};
struct Nod{
    int x,y,step;
}pos,p;
bool vis[10][10];
int solve(){
    queue<Nod> que;
    pos.x = sx;
    pos.y = sy;
    pos.step = 0;
    vis[sx][sy] = true;
    que.push(pos);
    while(que.size()){
        pos = que.front();
        que.pop();
        if(pos.x == gx && pos.y == gy) return pos.step;
        for(int i = 0; i < 8; i ++){
            int nx = pos.x + dis[i][0];
            int ny = pos.y + dis[i][1];
            if(0 <= nx && nx < 8 && 0 <= ny && ny < 8 && vis[nx][ny] == 0){
                p.x = nx; p.y = ny; p.step = pos.step + 1;
                vis[nx][ny] = 1;
                que.push(p);
            }
        }
    }
    return -1;
}

int main(){
    while(cin>>s>>ss){
        sx = s[0] - 'a';
        sy = ss[0] - 'a';
        gx = s[1] - '1';
        gy = ss[1] - '1';
        memset(vis, 0, sizeof(vis));
        int res = solve();
        printf("To get from %s to %s takes %d knight moves.\n",s,ss,res);
    }
}
