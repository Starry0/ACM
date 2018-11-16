#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int main() {
	ll n, k;
	cin >> n >> k;
	ll ans = 0, x, pre = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		if(i == n) {
			ans += (x+pre+k-1)/k;
			break;
		}
		if(pre > 0) {
			ans ++;
			x = max(0LL,x - (k-pre));
		}
		ans += x/k;
		pre = x-x/k*k;
	}
	printf("%lld\n",ans);
	return 0;
}