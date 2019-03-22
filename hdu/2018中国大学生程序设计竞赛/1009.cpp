#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
const ll mod = 1e9+7;
ll fac[N], sum[N], n, ans;
typedef pair<int,int> P;
vector<P> vs[N];

void dfs(int u, int fa) {
	sum[u] = 1;
	for(auto p : vs[u]) {
		int v = p.first, w = p.second;
		if(v == fa) continue;
		dfs(v, u);
		sum[u] += sum[v];
		ans += (sum[v]*(n-sum[v])%mod)*w%mod;
	}
}

int main() {
	int t, p;
	fac[0] = 1;
	for(int i = 1; i < N; i ++) fac[i] = (1LL*fac[i-1]*i) %mod;
	while(scanf("%lld", &n) != EOF) {
		ans = 0;
		for(int i = 0; i <= n; i ++) vs[i].clear(), sum[i] = 0;
		for(int i = 1; i < n; i ++) {
			int v, u, w;
			scanf("%d%d%d", &v, &u, &w);
			vs[v].push_back(P(u,w));
			vs[u].push_back(P(v,w));
		}
		dfs(1, 0);
		printf("%lld\n",2LL*(ans%mod) * fac[n-1] % mod);
	}
	return 0;
}