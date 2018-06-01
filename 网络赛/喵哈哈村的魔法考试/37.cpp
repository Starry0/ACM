#include  <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
int n, m, x1, yy, x2, y2;
char str[N][N];
int dist[N][N], dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
typedef pair<int, int> P;
int bfs(int x, int y) {
	memset(dist, -1, sizeof(dist));
	queue<P> que;
	que.push(P(x, y));
	dist[x][y] = 0;
	while(que.size()) {
		P p = que.front();
		que.pop();
		if(p.first == x2 && p.second == y2) break;
		for(int i = 0; i < 4; i ++) {
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if(0 < nx && nx <= n && 0 < ny && ny <= m && str[nx][ny] == '1' && dist[nx][ny] == -1) {
				que.push(P(nx,ny));
				dist[nx][ny] = dist[p.first][p.second] + 1;
			}
		}
	}
	return dist[x2][y2];
}
int main() {
	while(cin >> n >> m >> x1 >> yy >> x2 >> y2) {
		memset(str, 0, sizeof(str));
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) cin >> str[i][j];
		}
		printf("%d\n",bfs(x1, yy));
	}
	return 0;
}