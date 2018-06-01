#include <iostream>
#include <stdio.h>
using namespace std;
int str[110][110];
int n, m, gx, gy, len, flag;
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
void dfs(int x, int y, int flag,int step) {

	if(step == len) {
		printf("%d %d\n",x,y);
		return;
	}
	if(str[x][y] == 0) {
		flag = (flag - 1 + 4) %4;
		str[x][y] = 1;
		dfs(x+dx[flag],y+dy[flag],flag,step+1);
	}else {
		flag = (flag + 1) %4;
		str[x][y] = 0;
		dfs(x+dx[flag],y+dy[flag],flag,step+1);
	}
}
int main() {
	char str1[3];
	cin >> n >> m;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			cin >> str[i][j];
		}
	}
	cin >> gx >> gy >> str1 >> len;
	if(str1[0] == 'U') flag = 2;
	else if(str1[0] == 'D') flag = 0;
	else if(str1[0] == 'L') flag = 1;
	else if(str1[0] == 'R') flag = 3;
	dfs(gx,gy,flag,0);
	return 0;
}
/*
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0
*/