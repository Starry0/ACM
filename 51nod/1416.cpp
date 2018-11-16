#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char s[N][N];
int n, m, gx, gy;
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
bool vis[N][N], flag;
void dfs(int x, int y, char ch, int cnt) {
	if(flag) return;
	for(int i = 0; i < 4; i ++) {
		int nx = x+dx[i], ny = y+dy[i];
		if(gx == nx && gy == ny && cnt >= 4) {
			flag = true;return;
		}
		if(1 <= nx && nx <= n && 1 <= ny && ny <= m && !vis[nx][ny] && s[nx][ny] == ch) {
			vis[nx][ny] = 1;
			dfs(nx, ny, ch, cnt+1);
			vis[nx][ny] = 0;
		}
	}
}
int main(int argc, char const *argv[]) {
	while(cin >> n >> m) {
		flag = false;
		for(int i = 1; i <= n; i ++) cin >> s[i]+1;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				gx = i, gy = j;
				vis[i][j] = 1;
				dfs(i,j,s[i][j], 1);
				vis[i][j] = 0;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}