#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
ll max(ll x, ll y) {
	return x > y ? x: y;
}
int main() {
	ll n, x, k;
	cin >> n >> x >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a+1, a+1+n);
	ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		ll y = a[i] / x - (a[i]%x?0:1);
		//printf("%d %d\n",(y+k)*x,(y+k+1)*x);
		ans += lower_bound(a+1, a+1+n, (y+1+k)*x) - lower_bound(a+1,a+1+n,max((y+k)*x,a[i]));
	}
	cout << ans << endl;
	return 0;
}