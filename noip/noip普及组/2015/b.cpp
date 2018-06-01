#include <bits/stdc++.h>
using namespace std;
char str[110][110];
int ans[110][110];
int check(int x, int y) {
	int cnt = 0;
	if(str[x-1][y-1] == '*') cnt ++;
	if(str[x-1][y] == '*') cnt ++;
	if(str[x-1][y+1] == '*') cnt ++;
	if(str[x][y-1] == '*') cnt ++;
	if(str[x][y+1] == '*') cnt ++;
	if(str[x+1][y-1] == '*') cnt ++;
	if(str[x+1][y] == '*') cnt ++;
	if(str[x+1][y+1] == '*') cnt ++;
	return cnt;
}
int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i ++) cin >> str[i]+1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			ans[i][j] = check(i, j);
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(str[i][j] == '*') printf("*");
			else printf("%d",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}