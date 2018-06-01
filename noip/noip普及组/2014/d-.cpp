/*
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int a[20][20];
int n, m, r, c;
int fun(int x, int y) {
	int ans = 0;
	for(int i = x; i < x+r; i ++) {
		for(int j = y; j < y+c; j ++) {
			if(j != y) ans += abs(a[i][j] - a[i][j-1]);
			if(i != x) ans += abs(a[i][j] - a[i-1][j]);
		}
	}
	return ans;
}
int main() {
	int MIN = INF;
	cin >> n >> m >> r >> c;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n-r+1; i ++) {
		for(int j = 1; j <= m-c+1; j ++) {
			MIN = min(MIN, fun(i,j));
		}
	}
	printf("%d\n",MIN);
	return 0;
}
*/

