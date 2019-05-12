#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int M = 1e5+10;
char s[N][N];
int a[N][N], sum[2][N][N];
int n, m, k, len[M], ans[26];
char dir[M];

bool ok(int x, int y) {
	for(int i = 1; i <= k; i ++) {
		int nx, ny;
		if(dir[i] == 'N') nx = x - len[i], ny = y;
		if(dir[i] == 'S') nx = x + len[i], ny = y;
		if(dir[i] == 'E') ny = y + len[i], nx = x;
		if(dir[i] == 'W') ny = y - len[i], nx = x;
		if(1 <= nx && nx <= n && 1 <= ny && ny <= m) {
			int MINX = min(nx, x), MAXX = max(nx, x);
			int MINY = min(ny, y), MAXY = max(ny, y);
			if(nx == x) {
				if(MAXY-MINY+1 != sum[0][x][MAXY]-sum[0][x][MINY-1]) return false;
			} else {
				if(MAXX-MINX+1 != sum[1][MAXX][y]-sum[1][MINX-1][y]) return false;
			}  
		} else return false;
		x = nx, y = ny;
	}
	return true;
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) scanf("%s",s[i]+1);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(s[i][j] != '#') a[i][j] = 1;
			sum[0][i][j] = sum[0][i][j-1] + a[i][j];
			sum[1][i][j] = sum[1][i-1][j] + a[i][j];
		}
	}
	cin >> k;
	for(int i = 1; i <= k; i ++) cin >> dir[i] >> len[i];
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(s[i][j] >= 'A' && s[i][j] <= 'Z') {
				if(ok(i,j)) ans[cnt++] = s[i][j]-'A';
			}
		}
	}
	sort(ans,ans+cnt);
	for(int i = 0; i < cnt; i ++) printf("%c",ans[i]+'A');
	if(cnt == 0) printf("no solution\n");
	return 0;
}