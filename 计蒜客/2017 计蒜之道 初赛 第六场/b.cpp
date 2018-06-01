#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N = 55;
int n, k, m, x1, x2, yy, y2;
int a[N];
int dist[N][N];
int qx[N],qy[N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int d[N][N];
void init(){
	for(int i = 1; i <= n; i ++){
		int j;
		for(j = 1; j <= a[i]; j ++){
			dist[i][j] = 1;
		}
		for(;j <= n; j ++){
			dist[i][j] = 0;
		}
	}
}
int solve(){
	memset(d,-1,sizeof(d));
	queue<P> que;
	que.push(P(x1,yy));
	d[x1][yy] = 0;
	while(que.size()){
		P p = que.front();
		que.pop();
		if(p.first == x2 && p.second == y2) break;
		for(int i = 0; i < 4; i ++){
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if(0 < nx && nx <= n && 0 < ny && ny <= n && dist[nx][ny] == 1 && d[nx][ny] == -1){
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[x2][y2];
}
int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	init();
	cin >> m;
	for(int i = 1; i <= m; i ++){
		cin >> qx[i] >> qy[i];
	}
	int ans = 0;
	for(int i = 1; i <= m; i ++){
		x1 = qx[i]; yy = qy[i];
		for(int j = i+1; j <= m; j ++){
			if(i == j) continue;
			x2 = qx[j]; y2 = qy[j];
			int cnt = solve();
			//printf(" %d  %d : %d\n",i,j,cnt);
			if(cnt <= k) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}