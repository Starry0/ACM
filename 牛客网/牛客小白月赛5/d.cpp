#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cal(ll n) {
	if(n<5) return 0;
	else {
		n /= 5;
		return n+cal(n);
	}
}
int main() {
	ll n, ans = 0, y;
	cin >> n;
	ll cnt1 = 1, cnt2 = 5;
	y = n;
	while(n > 4) {
		for(ll i = n-n%5; i <= n; i ++) ans += cnt1*cal(i);
		n = n-n%5-1;
		ll tmp = n/5;
		ans += cnt2*(tmp+1)*tmp/2;
		n /= 5;
		cnt1*=5;cnt2*=5;
	}
	cout << ans << endl;
	return 0;
}