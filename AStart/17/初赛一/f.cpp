#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#define ll long long
#define INF = 0x3f3f3f3f
using namespace std;
const int N = 110;
const int M = 1010;
char str[N][N];
bool vis[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m;
void dfs(int x, int y, char c) {
    vis[x][y] = true;
    for(int i = 0; i < 4; i ++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx <= n+1 && 0 <= ny && ny <= m+1 && !vis[nx][ny] && str[nx][ny] == c) dfs(nx, ny, c);
    }
}
int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
        memset(vis, 0, sizeof(vis));
        memset(str, 0, sizeof(str));
        for(int i = 1; i <= n; i ++) scanf("%s", str[i]+1);
        for(int i = 0; i <= m+1; i ++) str[0][i] = str[n+1][i] = '0';
        for(int i = 0; i <= n+1; i ++) str[i][0] = str[i][m+1] = '0';
        int ans = 0, ans1 = 0;
        for(int i = 0; i <= n+1; i ++) {
            for(int j = 0; j <= m+1; j ++) {
                if(!vis[i][j]) {
                    if(str[i][j] == '1') {
                        ans ++;
                        dfs(i, j, '1');
                    } else if(str[i][j] == '0') {
                        ans1 ++;
                        dfs(i, j, '0');
                    }
                }
            }
        }
        if(ans == 1 && ans1 == 2) {
            printf("0\n");
        } else if(ans == 1 && ans1 == 1) {
            printf("1\n");
        } else printf("-1\n");
    }
    return 0;
}
