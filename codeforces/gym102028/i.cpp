#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
ll sum1[N], pre[N], sum[N];
int main() {
	int t, n;
	cin >> t;
	while(t--) {
		ll ans = 0;
		cin >> n;
		for(int i = 1; i < n; i ++) {
			cin >> a[i];
			ans += a[i];
		}
		for(int i = 1; i < n; i ++) {
			sum[i] = sum[i-1] + 1LL*i*a[i];
			sum1[i] = sum1[i-1] + a[i];
		}
		pre[n] = 0;
		for(int i = n-1; i >= 1; i --) {
			pre[i] = pre[i+1] + 1LL*(n-i)*a[i];
		}
		printf("0 %lld",ans);
		ll l = 2, r = n-1;
		for(int i = 3; i <= n; i ++) {
			ll lmax = ans + sum[l-1] + pre[r+1] + (n-r)*(sum1[r]-sum1[l-1]);
			ll rmax = ans + pre[r] + sum[l-1] + (l-1)*(sum1[r-1]-sum1[l-1]);
						// 10 + 4 + 0 + 1*
			// printf("-%lld %lld-\n",lmax,rmax );
			ans = max(lmax, rmax);
			if(lmax > rmax) l ++;
			else r --;
			printf(" %lld",ans);
		}
		printf("\n");

	}
	return 0;
}