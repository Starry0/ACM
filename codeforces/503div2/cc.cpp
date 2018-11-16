#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 5e3+10;
vector<ll> vs[N];
ll sum[N], n, m;
ll fun(ll x, ll le) {
	ll ans = 0, cnt = 0, res;
	for(int i = 2 ; i <= m ; i++) {
		res = 0;
		if(vs[i].size() >= x) 
			res = vs[i].size()-x+1;
		if(res > le) return INF;
		le -= res;
		for(int j = 0; j < res; j ++){
			ans += vs[i][j];
		}
		for(int j = res; j < vs[i].size(); j ++){
			sum[++cnt] = vs[i][j];
		}
	}
	sort(sum+1, sum+cnt+1);
	for(int i = 1 ; i <= le ; i ++ ) ans += sum[i];
	return ans ;
}

int main(){
	ll ans = INF;
	// cin >> n >> m;
	int x, y;
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d",&x,&y);
		vs[x].push_back(y);
		// printf("%dYES\n",i);
	}
	for(int i = 1; i <= m; i ++) sort(vs[i].begin(), vs[i].end());
	for(int i = vs[1].size(); i <= n; i ++) {
		ans = min(ans, fun(i, i-vs[1].size()));
	}
	printf("%lld\n",ans);
	return 0 ;
}

