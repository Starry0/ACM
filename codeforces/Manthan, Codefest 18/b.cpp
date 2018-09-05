#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
ll a[N];
int main() {
	ll n, s;
	cin >> n >> s;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a+1,a+1+n);
	ll ans = 0;
	if(a[n/2+1] < s) {
		for(int i = n/2+1; i <= n; i ++) {
			if(a[i] < s) ans += s-a[i];
		}
	} else {
		for(int i = n/2+1; i >= 1; -- i) {
			if(a[i] > s) ans += a[i] - s;
		}
	}
	printf("%lld\n",ans);
	return 0;
}