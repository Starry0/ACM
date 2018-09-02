#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	ll t, n, m, k, x, y;
	// scanf("%lld", &t);
	cin >> t;
	while(t--) {
		// scanf("%lld%lld%lld", &n, &m, &k);
		cin >> n >> m >> k;
		ll ans = 0;
		while(k--) {
			cin >> x >> y;
			ans += min(x,min(y,min(n-x,m-y)));
		}
		cout << ans << endl;
	}
	return 0;
}