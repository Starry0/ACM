#include <bits/stdc++.h>
using namespace std;
const int N = 33;
int str[N][N], n;
bool vis[N][N];
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
void dfs(int x, int y) {
	vis[x][y] = true;
	for(int i = 0; i < 4; i ++) {
		int nx = dx[i]+x, ny = dy[i]+y;
		if(0 < nx && nx <= n && 0 < ny && ny <= n && !str[nx][ny] && !vis[nx][ny]) {
			dfs(nx,ny);
		}
	}
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			cin >> str[i][j];
		}
	}
	for(int i = 1; i <= n; i ++) {
		if(str[1][i] == 0 && !vis[1][i]) dfs(1,i);
		if(str[n][i] == 0 && !vis[n][i]) dfs(n,i);
		if(str[i][1] == 0 && !vis[i][1]) dfs(i,1);
		if(str[i][n] == 0 && !vis[i][n]) dfs(i,n);
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(vis[i][j]) printf("0 ");
			else printf("%d ",str[i][j]==1?1:2);
		}
		printf("\n");
	}
	return 0;
}