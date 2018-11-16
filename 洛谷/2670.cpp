#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char s[N][N];
int fun(int x, int y) {
	int ans = 0;
	for(int i = -1; i <= 1; i ++) {
		for(int j = -1; j <= 1; j ++) {
			if(s[x+i][y+j] == '*') ans ++;
		}
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> s[i]+1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(s[i][j] == '?') {
				s[i][j] = '0'+fun(i,j);
			}
		}
	}
	for(int i = 1; i <= n; i ++) cout << s[i]+1 << endl;
	return 0;
}