#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 3e4+10;
typedef pair<ll,ll> P;
vector<P> vs[N];
ll n, v, u, w, MAX, s;
bool vis[N];
void dfs(ll u, ll fa, ll w) {
	if(w > MAX) {
		MAX = w;
		s = u;
	}
	for(int i = 0; i < vs[u].size(); i ++) {
		P p = vs[u][i];
		if(p.first == fa) continue;
		dfs(p.first, u, w+p.second);
	}
}
int main() {
	cin >> n;
	for(int i = 1; i < n; i ++) {
		cin >> u >> v >> w;
		vs[u].push_back(P(v,w));
		vs[v].push_back(P(u,w));
	}
	dfs(1, -1, 0);
	dfs(s, -1, 0);
	cout << MAX*10+MAX*(1+MAX)/2 << endl;
	return 0;
}