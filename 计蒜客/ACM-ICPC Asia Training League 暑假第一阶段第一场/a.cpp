#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
ll n, t, k;
ll fun(ll i) {
	ll ans = 1%n;
	while(i--) {
		ans *= k;
		ans %= n;
	}
	return ans;
}
int main() {
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld%lld",&n,&k);
		bool flag = false;
		ll i = 0;
		for(ll j = 1; j <= n; j*=2) {	
			if(fun(i) == 0) {
				printf("%lld\n",i);
				flag = true;
				break;
			}
			i++;
		}
		if(!flag) printf("unbounded\n");
	}
	return 0;
}