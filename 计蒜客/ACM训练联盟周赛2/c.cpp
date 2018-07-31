#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
typedef pair<int,int> P;
std::vector<P> pre[N];
std::vector<int> vs;
int cnt[N], sum[N];

int dfs(int v, int fa) {
	if(pre[v].size() > 2 || v == 1) return 0;
	for(int i = 0; i < pre[v].size(); i ++) {
		int u = pre[v][i].first, w = pre[v][i].second;
		if(u == fa) continue;
		return w + dfs(u,v);
	}
}
int main() {
	int t, n, q, u, v, w;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &q);
		memset(cnt,0,sizeof(cnt));
		memset(sum,0,sizeof(sum));
		for(int i = 1; i <= n; i ++) pre[i].clear();
		int ans = 0;
		for(int i = 0; i < n-1; i ++) {
			scanf("%d%d%d", &v, &u, &w);
			pre[u].push_back(P(v,w));
			pre[v].push_back(P(u,w));
			ans += w;
			cnt[u]++;cnt[v]++;
			sum[v]+=w;sum[u]+=w;
		}
		for(int i = 1; i <= n; i ++) {
			if(cnt[i] == 1) {
				sum[i] = dfs(i, -1);
				vs.push_back(sum[i]);
			}
		}
		sort(vs.begin(),vs.end());
		for(int i = 0; i < q; i ++) ans -= vs[i];
		printf("%d\n",ans);
		vs.clear();
	}
	return 0;
}