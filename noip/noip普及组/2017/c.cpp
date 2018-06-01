#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
int a[N][N], g[N][N], m, n;
int dx[] = {1, 0, -1, 0}, 
	dy[] = {0, 1, 0, -1};
void dfs(int x, int y, int flag) {
	//printf("(%d,%d)\n",x,y);
	for(int i = 0; i < 4; i ++) {
		int nx = dx[i] + x, ny = dy[i] + y;
		if(a[nx][ny] == -1 && flag != -1) continue;
		if(1 <= nx && nx <= m && 1 <= ny && ny <= m) {
			if(a[nx][ny] != -1) {
				if(a[nx][ny] == a[x][y] || a[nx][ny] == flag) {
					if(g[nx][ny] > g[x][y]) {
						g[nx][ny] = g[x][y];
						dfs(nx, ny, -1);
					}
				} else if(g[nx][ny] > g[x][y] + 1) {
					g[nx][ny] = g[x][y] + 1;
					dfs(nx, ny, -1);
				}
			} else if(flag == -1) {
				if(g[nx][ny] > g[x][y] + 2) {
					g[nx][ny] = g[x][y] + 2;
					dfs(nx, ny, a[x][y]);
				}
			 }
		}
	}
}
int main() {
	cin >> m >> n;
	memset(a, -1, sizeof(a));
	memset(g, INF, sizeof(g));
	for(int i = 1; i <= n; i ++) {
		int v, u, c;
		cin >> v >> u >>c;
		a[v][u] = c;
	}
	g[1][1] = 0;
	dfs(1, 1, -1);
	printf("%d\n",(g[m][m] == INF) ? -1: g[m][m]);
	return 0;
}