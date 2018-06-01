#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, MAX;
int a[N][N],dp[N][N];
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
void dfs(int x, int y) {
	for(int i = 0; i < 4; i ++) {
		int nx = dx[i]+x, ny = dy[i] + y;
			//cout << nx << ' ' << ny << endl;
		if(1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] > a[x][y] && dp[nx][ny] < dp[x][y]+1) {
			dp[nx][ny] = dp[x][y] + 1;
			MAX = max(dp[nx][ny],MAX);
			dfs(nx,ny);
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			dfs(i,j);
		}
	}
	cout << MAX+1<< endl;
	return 0;
}

1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
