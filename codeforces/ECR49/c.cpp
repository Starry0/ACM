#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
ll a[N], cnt = 0, b[N];
int main() {
	int t, n;
	cin >> t;
	while(t--) {
		scanf("%d", &n);
		cnt = 0;
		for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
		sort(a+1,a+1+n);
		for(int i = 1; i < n; i ++) {
			if(a[i] == a[i+1]) {
				b[cnt++] = a[i];
				i++;
			}
		}
		ll ans1 = b[0], ans2 = b[1];
		for(int i = 2; i < cnt; i ++) {
			if(ans1*b[i] < ans2*b[i-1]) {
				ans1 = b[i-1];
				ans2 = b[i];
			}
		}
		printf("%lld %lld %lld %lld\n",ans1,ans1,ans2,ans2);
	}
	return 0;
}