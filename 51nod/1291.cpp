#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
int c[N][N], U[N], S[N], cur;
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		string s;
		cin >> s;
		for(int j = 1; j <= m; j ++) U[j] = s[j-1]=='1'?U[j]+1:0;
		cur = 0;
		S[++cur] = 0;
		for(int j = 1; j <=m+1; ++ j) {
			while(U[j] < U[S[cur]]) {
				c[max(U[S[cur-1]], U[j])+1][j-S[cur-1]-1]++;
				c[U[S[cur]]+1][j-S[cur-1]-1] --;
				--cur;
			}
			while(cur >= 1 && U[j] == U[S[cur]]) --cur;
			S[++cur] = j;
		}
	}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++) c[i][j] += c[i-1][j];
	for(int i = 1; i <= n; i ++) {
		for(int j = m-1; j >= 1; j --) c[i][j] += c[i][j+1];
		for(int j = m-1; j >= 1; j --) c[i][j] += c[i][j+1];
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) printf("%d ",c[i][j]);printf("\n");
	}
	return 0;
}