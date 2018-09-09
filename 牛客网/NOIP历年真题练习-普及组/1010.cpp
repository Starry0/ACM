#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char s[N][N];

int check(int x, int y) {
	int ans = 0;
	for(int i = -1; i <= 1; i ++) {
		for(int j = -1; j <= 1; j ++) {
			if(i == 0 && j == 0) continue;
			if(s[x+i][y+j] == '*') ans++;
		}
	}
	return ans;
}
int main() {
	int n, m;
	memset(s, 0, sizeof(s));
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> s[i]+1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(s[i][j] == '?') {
				s[i][j] = check(i, j) + '0';
			}
		}
	}
	for(int i = 1; i <= n; i ++) printf("%s\n",s[i]+1);
	return 0;
}