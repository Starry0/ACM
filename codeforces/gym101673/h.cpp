#include <bits/stdc++.h>
using namespace std;
char s[110][110];
bool vis[110][110];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for(int i = -1; i <= 1; i ++) {
        for(int j = -1; j <= 1; j ++) {
            if(i == j && i == 0) continue;
            if(s[x+i][y+j] == '#' && vis[x+i][y+j] == 0) dfs(x+i,y+j);
        }
    }
}

int main( ) {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> s[i]+1;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(!vis[i][j] && s[i][j] == '#') {
                ans++;
                dfs(i,j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}