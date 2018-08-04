#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int t, n, m, x, y;
char s[N][N];
int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; i ++) cin >> s[i]+1;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				if(s[i][j] == 'S') {
					x = i, y = j;
				}
			}
		}
		int mi = N, mx = 0, MI = N, MX = 0;
		for(int i = 1; i <= n; i ++) {
			if(s[i][y] == '#') {
				mi = min(mi, i);
				mx = max(mx, i);
			}
		}
		for(int i = 1; i <= m; i ++) {
			if(s[x][i] == '#') {
				MI = min(mi, i);
				MX = max(mx, i);
			}
		}
		if(MI != N || mi != N || mx != 0 || MX != 0) {
			printf("-1\n");
		} else printf("%d\n",n+m-2 );
	}
	return 0;
}