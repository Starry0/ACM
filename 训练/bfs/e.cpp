#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e3;
string s[maxn];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n, m, sx, sy, gx, gy;
typedef pair<int, int> P;

void bfs(){
    queue<P> que;
    que.push(P(sx, sy));
    while(que.size()){
        P p = que.front();
        que.pop();
        for(int i = 0; i < 4; i ++){
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(s[nx][ny] == 'X'){
                    if(nx == gx && ny == gy){
                        puts("YES");
                        return;
                    }
                }else{
                    s[nx][ny] = 'X';
                    que.push(P(nx, ny));
                }
            }
        }
    }
    puts("NO");
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i = 0; i < n; i ++) cin >> s[i];
        scanf("%d%d%d%d",&sx,&sy,&gx,&gy);
        sx--;sy--;gx--;gy--;
        bfs();
    }
    return 0;
}
