#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
ll min(ll x, ll y) {
	return x<y?x:y;
}
int main() {
	int t, n;
	cin >> t;
	while(t--) {
		priority_queue<ll, vector<ll>, greater<ll> > que;
		cin >> n;
		for(int i = 1; i <= n; i ++) {
			que.push(1LL);
		}
		ll ans = 0;
		while(que.size() != 1) {
			ll a = que.top(); que.pop();
			ll b = que.top(); que.pop();
			ans += min(a,b);
			que.push(a+b);
		}
		cout << ans << endl;
	}
	return 0;
}
