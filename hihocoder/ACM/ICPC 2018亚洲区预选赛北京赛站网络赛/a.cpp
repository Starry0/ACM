#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 110;
int n, m;
char str[N][N];
set<int> st[N][N];
bool vis[N][N][6];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
struct Nod{
	int x, y, ans, b;
	Nod() {
		x = y = ans = b = 0;
	}
	Nod(int x, int y, int ans, int b):x(x),y(y),ans(ans),b(b){}
	bool operator < (const Nod a) const {
		return a.ans < ans;
	}
};
int bfs(Nod & s) {
	priority_queue<Nod> que;
	que.push(s);
	vis[s.x][s.y][0] = 1;
	int ans = INF;
	int res = 0;
	while(que.size()) {
		Nod q = que.top(); que.pop();
		// printf("%d %d %d %d\n",q.x,q.y,q.ans,q.b);
		// if(q.ans > n*m*5*100) return -1;
		if(str[q.x][q.y] == 'T') {
			// printf("%d\n",res);
			if(ans > q.ans) ans = q.ans;
			else if(q.ans > ans+2) return ans;
		}
		for(int i = 0; i < 4; i ++) {
			res++;
			int nx = dx[i] + q.x, ny = dy[i] + q.y;
			if( 1 > nx || nx > n || ny < 1 || ny > m) continue;
			int cnt = q.b;
			if(str[nx][ny] == '#' && cnt == 0) continue;
			// printf("s:%d %d\n", nx,ny);
			if(str[nx][ny] == 'B') cnt = min(cnt+1, 5);
			// printf("%d %d -> %d %d\n",q.x,q.y,nx,ny );
			if(str[q.x][q.y] == 'P') {
				if(str[nx][ny] == '#') {
					cnt--;
					if(!vis[nx][ny][cnt] || !st[nx][ny].count(q.ans+1)) {
						st[nx][ny].insert(q.ans+1);
						que.push(Nod(nx, ny, q.ans+1, cnt));
					}
				} else {
					if(!vis[nx][ny][cnt] || !st[nx][ny].count(q.ans)){
						que.push(Nod(nx, ny, q.ans, cnt));
						st[nx][ny].insert(q.ans);
					}
				}
			} else {
				if(str[nx][ny] == '#') {
					cnt--;
					if(!vis[nx][ny][cnt] || !st[nx][ny].count(q.ans+2)){
						st[nx][ny].insert(q.ans+2);
						que.push(Nod(nx, ny, q.ans+2, cnt));
					}
				} else {
					if(!vis[nx][ny][cnt] || !st[nx][ny].count(q.ans+1)){
						st[nx][ny].insert(q.ans+1);
						que.push(Nod(nx, ny, q.ans+1, cnt));
					}
				}
			}
			vis[nx][ny][cnt] = 1;
		}
	}
	return (ans!= INF)?ans:-1;
}
int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n==0 && m == 0) break;
		memset(vis, 0, sizeof(vis));
		memset(str, 0, sizeof(str));
		for(int i = 1; i <= n; i ++) scanf("%s", str[i]+1);
		Nod start;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				st[i][j].clear();
				if(str[i][j] == 'S') {
					start.x = i, start.y = j;
				}
			}
		}
		printf("%d\n", bfs(start));
	}
	return 0;
}