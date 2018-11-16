#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1100;
char s[N][N];
bool vis[N][N];
struct Nod {
	int x, y, s;
}e[N*N];
std::vector<Nod> vs;
int n, m;
void solve(int x, int y) {
	int ans = 0, cnt = 1;
	while(x-cnt >= 1 && x+cnt <= n && y-cnt >= 1 && y+cnt <= m) {
		if(s[x-cnt][y] == '*' && s[x+cnt][y] == '*' && s[x][y+cnt] == '*' && s[x][y-cnt] == '*') {
			ans++;
			vis[x-cnt][y]=vis[x+cnt][y]=vis[x][y-cnt]=vis[x][y+cnt]=vis[x][y] = 1;
		} else break;
		cnt++;
	}
	if(ans == 0) return;
	struct Nod p;
	p.x = x, p.y = y, p.s = ans;
	vs.push_back(p);
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> s[i]+1;
	for(int i = 2; i <= n-1; i ++) {
		for(int j = 2; j <= m-1; j ++) {
			if(s[i][j] == '*') solve(i,j);
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(s[i][j]=='*') {
				if(vis[i][j]==0) return 0*printf("-1\n");
			}
		}
	}
	printf("%d\n",vs.size());
	for(int i = 0; i < vs.size(); i ++) {
		printf("%d %d %d\n",vs[i].x,vs[i].y,vs[i].s);
	}
	return 0;
}