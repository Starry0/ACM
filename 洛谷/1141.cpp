#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char str[N][N];
int vis[N][N], cnt = 1, res[N*N], n, m;
int dx[] = {1,0,-1,0}, dy[] = {0,-1,0,1};
struct Nod{
	int x, y;
}nod,q;
int bfs() {
	int ans = 0;
	queue<Nod> que;
	que.push(q);
	vis[q.x][q.y] = cnt;
	while(que.size()) {
		q = que.front();
		que.pop();
		ans++;
		for(int i = 0; i < 4; i ++) {
			int nx = dx[i]+q.x, ny = dy[i]+q.y;
			if(1 <= q.x && q.x <= n && 1 <= q.y && q.y <= n && str[q.x][q.y] != str[nx][ny] && !vis[nx][ny]) {
				nod.x = nx;
				nod.y = ny;
				vis[nx][ny] = cnt;
				que.push(nod);
			}
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <=n; i ++) scanf("%s",str[i]+1);
	while(m--) {
		cin >> q.x >> q.y;
		if(vis[q.x][q.y]) {
			cout << res[vis[q.x][q.y]] << endl;
		} else {
			cnt++;
			res[cnt] = bfs();
			cout << res[cnt] << endl;
		}
	}
	return 0;
}