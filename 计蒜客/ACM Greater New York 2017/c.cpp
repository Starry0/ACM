/*#include <bits/stdc++.h>
using namespace std;
const int N = 10;
char s[N][N], ch;
bool vis[N][N], vis1[N*N][N*N];
int ans[N][N], cnt[N*N];
int p, k, c, r, n, a, x, y, res;
bool flag;
bool ok(int x1, int y1, int tmp) {
	for(int i = -1; i <= 1; i ++) {
		for(int j = -1; j <= 1; j ++) {
			if(i == 0 && j == 0) continue;
			if(x1+i < 1 || x1+i > c || y1+j < 1 || y1+j > r) continue;
			if(s[x1+i][y1+j]-'0' == tmp) return false;
		}
	}
	return true;
}
void dfs(int x, int y, int de) {
	if(res+de > c*r || flag) return; 
	if(res+de == c*r) {
		flag = true;
		return;
	}
	for(int nx = -1; nx <= 1; nx ++) {
		for(int ny = -1; ny <= 1; ny ++) {
			if(nx == 0 && ny == 0) continue;
			if(nx+x < 1 || nx+x > c || ny+y < 1 || ny+y > r) continue;
			if(s[nx+x][ny+y] != '-') continue;
			int tmp = 1;
			// printf("%d %d\n",nx+x,ny+y );
			for(int tmp = 1; tmp <= cnt[ans[nx+x][ny+y]]; ++ tmp) {
				if(!vis1[ans[nx+x][ny+y]][tmp] && ok(nx+x,ny+y,tmp)) {
					s[nx+x][ny+y] = tmp+'0';
					vis1[ans[nx+x][ny+y]][tmp] = true;
					dfs(nx+x,ny+y,de+1);
					if(flag) return;
					vis1[ans[nx+x][ny+y]][tmp] = false;
					s[nx+x][ny+y] = '-';
				}
			}
		}
	}
}

int main() {
	int xxx, yyy;
	cin >> p;
	while(p--) {
		flag = false;
		res = 0;
		cin >> k >> c >> r;
		for(int i = 1; i <= c; i ++) {
			for(int j = 1; j <= r; j ++) cin >> s[i][j];
		}
		cin >> n;
		for(int i = 1; i <= n; i ++) {
			cin >> a;
			for(int j = 1; j <= a; j ++) {
				cin >> ch >> x >> ch >> y >> ch;
				ans[x][y] = i;
			}
			cnt[i] = a;
		}
		for(int i = 1; i <= c; i ++) {
			for(int j = 1; j <= r; j ++) {
				if(s[i][j] != '-') {
					res ++;
					vis1[ans[i][j]][s[i][j]-'0'] = true;
				}
			}
		}
		for(int i = 1; i <= c; i ++) {
			for(int j = 1; j <= r; j ++) {
				if(flag)break;
				if(s[i][j] != '-') {
					dfs(i,j,0);
				}
			}
			if(flag)break;
		}
		for(int i = 1; i <= c; i ++) printf("%s\n",s[i]+1);
		memset(s, 0, sizeof(s));
	}
	return 0;
}*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10;
char s[N][N];
int cnt[N*N], ans[N][N];
bool cou[N][N][N*N];
set<int> st[N][N];
set<int>::iterator it;
int p, k, c, r, n, a, x, y, res;

void del(int x, int y, int tmp) {
	for(int i = -1; i <= 1; i ++) {
		for(int j = -1; j <= 1; j ++) {
			st[i][j][tmp] = 1;
		}
	}
}

void dfs(int x, int y) {

}
int main() {
	cin >> p;
	while(p--) {
		flag = false;
		res = 0;
		cin >> k >> c >> r;
		for(int i = 1; i <= c; i ++) {
			for(int j = 1; j <= r; j ++) cin >> s[i][j];
		}
		cin >> n;
		for(int i = 1; i <= n; i ++) {
			cin >> a;
			for(int j = 1; j <= a; j ++) {
				cin >> ch >> x >> ch >> y >> ch;
				ans[x][y] = i;
				if(a == 1) s[x][y] = '1';
			}
			cnt[i] = a;
		}
		for(int i = 1; i <= c; i ++) {
			for(int j = 1; j <= r; j ++) {
				if(s[i][j] != '-') {
					del(i,j,s[i][j]-'0');
					res++;
				}
			}
		}
		for(int i = 1; i <= c; i ++) {
			for(int j = 1; j <= r; j ++) {
				if(s[i][j] == '-') {
					dfs(i,j);
				}
			}
		}
	}
	return 0;
}