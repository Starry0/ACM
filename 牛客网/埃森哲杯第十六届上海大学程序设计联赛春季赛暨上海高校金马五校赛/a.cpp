#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
const int N = 100010;
ll a[N], b[N];
int main() {
	ll t, n;
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld",&n);
		ll ans = 0;
		for(int i = 1; i <= n; i ++) scanf("%lld",&a[i]);
		for(int i = 1; i <= n; i ++) scanf("%lld",&b[i]);
		for(ll i = 1; i <= n; i ++) {
			if(a[i] == b[i])continue;
			if(a[i] > b[i]) {
				a[i+1] += a[i] - b[i];
				ans += a[i] - b[i];
			//	printf("1:%d\n",ans);
			}
			if(a[i] < b[i]) { 
				ll tmp = b[i]-a[i];
				for(ll j = i+1; j <= n; j ++) {
					if(tmp >= a[j]) {
						ans += abs(j-i)*a[j];
						//printf("2:%d\n",ans);
						tmp -= a[j];
						a[j] = 0;
					} else{
						ans += (j-i)*tmp;
						//printf("3:%d\n",ans);
						a[j] -= tmp;
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}