#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 20;
int n, m, u, v, w;
int dp[N];
typedef pair<int,int> P;
vector<P> vs[N];
bool cmp(P a, P b) {
	return a.second < b.second;
}
void dfs(int x, int de) {
	for(auto u : vs[x]) {
		if(dp[u.first] > u.second*de) {
			dp[u.first] = u.second*de;
			dfs(u.first, de+1);
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		cin >> u >> v >> w;
		vs[u].push_back(P(v,w));
		vs[v].push_back(P(u,w));
	}
	for(int i = 1; i <= n; i ++) sort(vs[i].begin(), vs[i].end(), cmp);
	int ans = INF, cnt;
	for(int i = 1; i <= n; i ++) {
		memset(dp, INF, sizeof(dp));
		cnt = dp[i] = 0;
		dfs(i, 1);
		for(int i = 1; i <= n; i ++) cnt += dp[i];
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}