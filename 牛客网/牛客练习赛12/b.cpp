#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 550;
char str[N][N];
int vis[N][N], xx[4], yy[4], ans;
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
struct Nod {
	int x, y, step;
}pos, q;

int bfs(int x, int y, int gx, int gy) {
	queue<Nod> que;
	pos.x = x, pos.y = y;
	pos.step = 0;
	que.push(pos);
	vis[x][y] = 1;
	while(que.size()) {
		q = que.front();
		que.pop();
		if(q.x == gx && q.y == gy) return q.step;
		for(int i = 0; i < 4; i ++) {
			int nx = q.x + dx[i], ny = q.y + dy[i];
			if(str[nx][ny] != 'W' && vis[nx][ny] == 0 && str[nx][ny] == '.' ) {
				pos.x = nx, pos.y = ny;
				pos.step = q.step + 1;
				que.push(pos);
				vis[nx][ny] = 1;
			}
		}
	}
	return -1;
}
void init(){
	for(int i = 0; i < N; i ++) {
		for(int j = 0; j < N; j ++) {
			vis[i][j] = 0;
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> str[i]+1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(str[i][j] == 'S') {
				xx[0] = i; yy[0] = j;
			} 
			if(str[i][j] == 'E') {
				xx[1] = i; yy[1] = j;
			}
			if(str[i][j] == 'K') {
				xx[2] = i; yy[2] = j;
			}
			if(str[i][j] == 'D') {
				xx[3] = i; yy[3] = j;
			}
		}
	}
	str[xx[0]][yy[0]] = str[xx[2]][yy[2]] = str[xx[1]][yy[1]] = '.';
	init();
	int ans0 = bfs(xx[0],yy[0],xx[1],yy[1]);
	init();
	int ans1 = bfs(xx[0],yy[0],xx[2],yy[2]);
	init();
	str[xx[3]][yy[3]] = '.';
	int ans2 = bfs(xx[2],yy[2],xx[3],yy[3]);
	init();
	int ans3 = bfs(xx[3],yy[3],xx[1],yy[1]);
	int ans4 = -1;
	if(ans0 != -1) ans4 = ans0;
	if(ans1 != -1 && ans2 != -1 && ans3 != -1) {
		if(ans0 == -1) ans4 = ans1+ans2+ans3;
		else ans4 = min(ans4, ans1+ans2+ans3);
	}
	
	printf("%d\n",ans4);
	return 0;
}