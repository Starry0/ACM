#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int t, n, m, gx, gy, xx, yy;
const int N = 550;
char str[N][N];
int d[N][N];
int dx[] = {1,0,-1,0}, dy[] = {0, 1, 0, -1};
typedef pair<int, int> P;
map<P,int> mp1, mp2;
void bfs(int x1, int y1,int flag) {
	memset(d,-1,sizeof(d));
	queue<P> que;
	que.push(P(x1,y1));
	d[x1][y1] = 0;
	while(que.size()) {
		P p = que.front(); que.pop();
		for(int i = 0; i < 4; i ++) {
			int nx = dx[i] + p.first, ny = dy[i] + p.second;
			if(1 <= nx && nx <= n && 1 <= ny && ny <= m && str[nx][ny] != '#' && d[nx][ny] == -1) {
				if(flag && str[nx][ny] != 'E') {
					que.push(P(nx,ny));
					d[nx][ny] = d[p.first][p.second] + 1;
					if(str[nx][ny] == 'K') mp1[make_pair(nx,ny)] = d[nx][ny];
				} else if(!flag && str[nx][ny] != 'P') {
					que.push(P(nx,ny));
					d[nx][ny] = d[p.first][p.second] + 1;
					if(str[nx][ny] == 'K') mp2[make_pair(nx,ny)] = d[nx][ny];
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		cin >> n >> m;
		memset(str,0,sizeof(str));
		mp1.clear();
		mp2.clear();
		for(int i = 1; i <= n; i ++) cin >> str[i] + 1;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				if(str[i][j] == 'P') {
					gx = i;
					gy = j;
				}
				if(str[i][j] == 'E') {
					xx = i;
					yy = j;
				}
			}
		}
		int MIN = INF;
		bfs(gx,gy,1);
		bfs(xx,yy,0);
		if(mp1.size()&&mp2.size()) {
			map<P,int> :: iterator it = mp1.begin();
			for(; it != mp1.end(); it++) {
				if(mp2.count((*it).first))
				MIN = min(MIN,(*it).second+mp2[(*it).first]);
			}
			printf("%d\n",MIN);
		} else printf("No solution\n",MIN);
	}
	return 0;
}