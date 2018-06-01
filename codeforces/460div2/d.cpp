#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
char str[N];
int n, m, x, y, ans;
vector<int> vs[N];
int vis[N];
int dp[N][26];

void dfs(int u) {
	vis[u] = 1;
	dp[u][str[u]-'a'] = 1;
	for(int i = 0; i < vs[u].size(); i ++) {
		int v = vs[u][i];
		if(vis[v] == 1) {
			printf("-1\n");
			exit(0);
		} else{
			if(!vis[v]) dfs(v);
			for(int j = 0; j < 26; j ++) {
				dp[u][j] = max(dp[u][j],dp[v][j]+(str[u]-'a' == j));
			}
		}
	}
	vis[u] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> str+1;
	for(int i = 0; i < m; i ++) {
		cin >> x >> y;
		vs[x].push_back(y);
	}
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i ++) {
		if(!vis[i]) {
			dfs(i);
			for(int j = 0; j < 26; j ++) {
				ans = max(ans,dp[i][j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}