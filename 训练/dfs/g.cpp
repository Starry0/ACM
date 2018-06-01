#include <iostream>
#include <cstdio>
using namespace std;
int n, m, maxn, dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
char a[25][25];
bool vis[25][25], ap[30];
void dfs(int x, int y, int ans){
    for(int i = 0; i < 4; i ++){
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && vis[nx][ny] == false && ap[a[nx][ny]-'A'] == false){
            vis[nx][ny] = true;
            ap[a[nx][ny]-'A'] = true;
            //cout << nx << ' ' << ny << ' ' << ans << endl;
            dfs(nx, ny, ans+1);
            vis[nx][ny] = false;
            ap[a[nx][ny]-'A'] = false;
        }
        else maxn = max(maxn, ans);
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        maxn = 1;
        for(int i = 0; i < n; i ++) cin >> a[i];
        vis[0][0] = true;
        ap[a[0][0]-'A'] = true;
        dfs(0,0,1);
        cout << maxn << endl;
    }
}
