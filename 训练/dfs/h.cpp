#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
char a[110][110];
void dfs(int x, int y){
    a[x][y] = '*';
    for(int i = -1; i <= 1; i ++){
        for(int j = -1; j <= 1; j++){
            int nx = x + i, ny = y + j;
            if(0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == '@')dfs(nx, ny);
        }
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)&&n&&m){
        int ans = 0;
        for(int i = 0; i < n; i ++) cin >> a[i];
        for(int i = 0 ; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(a[i][j] == '@'){
                    ans ++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
}
