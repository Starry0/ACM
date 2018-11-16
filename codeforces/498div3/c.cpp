#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
ll n, a[N], sum[N], pre[N];
bool ok(int l, int r, ll cnt) {
	while(l <= r) {
		int m = (l+r) >> 1;
		if(pre[m] == cnt) return true;
		if(pre[m] > cnt) l = m+1;
		else r = m-1;
	}
	return false;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	for(int i = n; i >= 0; i --) pre[i] = pre[i+1] + a[i];
	ll MAX = 0;
	for(int i = 1; i <= n; i ++) {
		ll ans = sum[i];
		if(ok(i+1,n, ans)) {
			MAX = ans;
		}
	}
	printf("%lld\n",MAX);
	return 0;
}