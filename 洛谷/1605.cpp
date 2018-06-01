#include <bits/stdc++.h>
using namespace std;
int n, m, t, gx, gy, ex, ey, ans;
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int vis[6][6];

void dfs(int x, int y) {
	if(x == ex && y == ey) {
		ans ++;
		return;
	}
	for(int i = 0; i < 4; i ++) {
		int nx = x+dx[i], ny = y+dy[i];
		if(0 < nx && nx <= n && 0 < ny && ny <= m && !vis[nx][ny]) {
			vis[x][y] = 1;
			dfs(nx,ny);
			vis[x][y] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> t;
	cin >> gx >> gy >> ex >> ey;
	while(t--) {
		int x, y;
		cin >> x >> y;
		vis[x][y] = 1;
	}
	dfs(gx,gy);
	cout << ans << endl;
	return 0;
}