#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
const ll INF = 1e17;
typedef pair<int,ll> P;
vector<P> vs[N], vs1[N];
int n, m, k, u, v, t;
bool vis[N], vis1[N];
ll w, MIN;
multiset<ll> st;
multiset<ll> ::reverse_iterator it;
void dfs(int u, int res, ll val) {
	ll ans = val, cnt = 0;
	for(it = st.rbegin(); it != st.rend(); ++ it) {
		if(cnt == k) break; 
		ans -= (*it);
		cnt++;
	}
	if(ans >= MIN) return;
	if(u == n) {
		MIN = min(MIN, ans);
		return;
	}
	for(int i = 0; i < vs[u].size(); i ++) {
		P p = vs[u][i];
		int v = p.first; ll cost = p.second;
		if(!vis[v]&&vis1[v]) {
			vis[v] = 1;
			st.insert(cost);
			dfs(v, res+1, val+cost);
			st.erase(cost);
			vis[v] = 0;
		}
	}
}
void dfs(int u) {
	vis1[u] = 1;
	for(int i = 0; i < vs1[u].size(); i ++) {
		P p = vs1[u][i];
		if(!vis1[p.first]) {
			dfs(p.first);
		}
	}
}
int main() {
	scanf("%d", &t);
	while(t--) {
		MIN = INF;
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= n; i ++) {
			vs[i].clear(); vs1[i].clear();
			vis[i] = vis1[i] = 0;
		}
		st.clear();
		for(int i = 1; i <= m; i ++) {
			scanf("%d%d%lld", &v, &u, &w);
			vs[v].push_back(P(u,w));
			vs1[u].push_back(P(v,w));
		}
		vis[1] = 1;
		dfs(n);
		dfs(1,0,0);
		printf("%lld\n",MIN);
	}
	return 0;
}