#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char a[110][110];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1},  h, w, ans;
bool vis[110][110];

void dfs(int x, int y, char c){
    vis[x][y] = true;
    for(int i = 0; i < 4; i ++){
        int xx = x+dx[i], yy = y + dy[i];
        if(0 <= xx && xx < h && 0 <= yy && yy < w && a[xx][yy] == c && !vis[xx][yy]){
            dfs(xx,yy,c);
        }
    }
}

int main(){
    while(cin>>h>>w){
        if(h==0&w==0) break;
        memset(a,0,sizeof(a));
        memset(vis,false,sizeof(vis));
        ans = 0;
        // for(int i = 0; i < h; i ++) gets(a[i]);
        for(int i = 0; i < h; i ++)
        for(int j = 0; j < w; j ++)
        cin>>a[i][j];
        for(int i = 0; i < h; i ++){
            for(int j = 0; j < w; j ++){
                if(!vis[i][j]){
                    ans++;
                    dfs(i,j,a[i][j]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
