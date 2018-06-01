#include <iostream>
#include <string.h>
using namespace std;
char a[21][21];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1}, ans, n, m;
bool vis[21][21];

void dfs(int x, int y){
    a[y][x] = '#';
    vis[y][x] = true;
    ans++;
    for(int i = 0 ; i < 4; i ++){
        int xx = x + dx[i], yy = y + dy[i];
        if(0 <= xx && xx < n && 0 <= yy && yy < m && a[yy][xx] =='.' && vis[yy][xx] == false){
            dfs(xx,yy);
        }
    }
}

int main(){
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        memset(a,0,sizeof(a));
        memset(vis,false,sizeof(vis));
        ans = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                cin >> a[i][j];
            }
        }

        int xx, yy;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(a[i][j] == '@'){
                    xx = j; yy = i;
                    break;
                }
            }
        }
        dfs(xx,yy);
        cout << ans << endl;
    }
    return 0;
}
