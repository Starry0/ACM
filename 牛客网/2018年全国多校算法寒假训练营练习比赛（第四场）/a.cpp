#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
char str[N][N];
int t, n, ans1, ans2;
void dfs(int x, int y) {
	if(1 > x || x > n || 1 > y || y > n || str[x][y] == '.') return;
	((x+y)&1)?ans1++:ans2++;
	str[x][y] = '.';
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y-1);
	dfs(x,y+1);
}
int main() {
	cin >> t;
	for(int ca = 1; ca <= t; ca ++) {
		cin >> n;
		for(int i = 1; i <= n; i ++) cin >> str[i]+1;
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				if(str[i][j] == '#') {
					ans1 = ans2 = 0;
					dfs(i,j);
					ans += min(ans1, ans2);
				}
			}
		}
		printf("Case %d: %d\n",ca,ans);
	}
	return 0;
}
