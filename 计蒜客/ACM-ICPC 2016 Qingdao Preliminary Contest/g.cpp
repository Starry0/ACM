#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
const ll MAX = 1e9+10;
ll a[N];
ll t, n, x, T;
priority_queue<ll, vector<ll>,greater<ll> > que, que1;

bool ok(ll m) {
	que1 = que;
	ll ans = 0, cnt, res = 0;
	while((que1.size()-1)%(m-1) != 0) {
		res += que1.top();
		que1.pop();

	}
	while(!que1.empty()) {
		cnt = 0;
		if(que1.size() == 1) break;
		for(int i = 0; i < m; i ++) {
			cnt += que1.top();
			que1.pop();
		}
		ans += cnt;
		que1.push(cnt);
	}
	if(res != 0) {
		ans += res+que1.top();
	}
	// printf("%lld %lld\n",m,ans);
	return ans <= T;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%lld", &t);
	while(t--) {
		while(!que.empty()) que.pop();
		scanf("%lld %lld", &n, &T);
		for(int i = 1; i <= n; i ++) {
			scanf("%lld", &x);
			que.push(x);
		}	
		ll l = 2, r = n, ans = n;
		while(l <= r) {
			ll m = (l+r)>>1;
			if(ok(m)) {
				ans = m;
				r = m-1;
			} else l = m+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}