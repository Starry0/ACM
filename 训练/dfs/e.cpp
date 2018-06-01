#include <iostream>
#include <cstdio>
using namespace std;
int n, m, ans;
char a[50][50];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
void dfs(int x, int y){
    a[x][y] = '#';
    for(int i = 0; i < 4; i ++){
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == '.'){
            ans ++;
            dfs(nx,ny);
        }
    }
}
int main(){
    while(~scanf("%d%d",&m,&n)&&m&&n){
        ans = 1;
        for(int i = 0; i < n; i ++) cin >> a[i];
        int nx, ny;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(a[i][j] == '@'){
                    nx = i; ny = j;
                    goto tt;
                }
            }
        }
        tt: ;
        dfs(nx, ny);
        cout << ans << endl;
    }
}
