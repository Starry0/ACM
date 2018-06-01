#include <bits/stdc++.h>
using namespace std;
const int N = 150;
char str[N][N];
int n;
void dfs(int x, int y) {
	if(x == n/2+1) {
		str[x][y] = '$';
		return;
	}
	str[x][y] = '$';
	str[x][y+1] = '.';
	str[x+1][y] = '.';
	str[x+1][y+1] = '.';
	for(int i = x+2; i <= n/2+1; i ++) {
		str[x][i] = str[i][x] = '$';
	}
	str[x+1][y+2] = str[x+2][y+1] = '$';
	for(int i = x+3; i <= n/2+1; i ++) {
		str[x+1][i] = str[i][x+1] = '.';
	}
	dfs(x+2,y+2);
}
int main() {
	cin >> n;
	n = 5+4*n;
	dfs(1,1);
	str[1][1] = '.';
	for(int i = 1; i <= n/2+1; i ++) {
		for(int j = n/2+2; j <= n; j ++) {
			str[i][j] = str[i][n-j+1];
		}
	}
	for(int i = n/2+2; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			str[i][j] = str[n-i+1][j];
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			cout << str[i][j];
		}
		cout << endl;
	}
	return 0;
}

/*
1 9
2 13
3 17

..$$$
..$..
$$$.$
$...$
$.$$$

..$$$$$$$
..$......
$$$.$$$$$
$...$....
$.$$$.$$$
$.$...$..
$.$.$$$.$
$.$.$...$
$.$.$.$$$
*/