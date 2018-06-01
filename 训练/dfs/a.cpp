#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int vis[30];
char a[110][110];
int n, m, ans = 0;
char c;
void dfs(int x, int y){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && isalpha(a[nx][ny]) && a[nx][ny] != c && vis[a[nx][ny] - 'A'] == 0){
            vis[a[nx][ny]-'A'] = 1;
            ans++;
            a[nx][ny] = '.';
        }
    }
}

int main(){
    while(cin>>n>>m>>c){
        memset(vis, 0, sizeof(vis));
        ans = 0;
        for(int i = 0; i < n; i ++) cin >> a[i];
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(a[i][j] == c){
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
}
