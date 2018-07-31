#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t, n;
ll m, a[20];
int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 0; i < n; i ++) cin >> a[i];
		ll ans = 0;
		for(int state = 1; state < (1<<n); ++state) {
			ll cnt = 0, _lcm = 1;
			for(int i = 0; i < n; i ++) {
				if(state&(1<<i)) {
					_lcm = _lcm/__gcd(a[i],_lcm)*a[i];
					cnt ++;
					if(_lcm > m) break;
				}
			}
			ans += cnt%2 ? m/_lcm: -m/_lcm;
		}
		cout << ans << endl;
	}
	return 0;
}