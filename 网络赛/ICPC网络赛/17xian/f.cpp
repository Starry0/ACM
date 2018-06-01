#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
void exgcd(ll a, ll b, ll &x, ll &y) {
    if(!b){
        x = 1; y = 0;
    }else{
        exgcd(b, a%b, y, x);
        y -= x*(a/b);
    }
}
ll inv(ll a, ll n) {
    ll x, y;
    exgcd(a, n, x, y);
    return (x+n)%n;
}
int main() {
	ll n, m;
	while(scanf("%lld %lld", &n, &m) != EOF) {
		ll x = (n + m - 2);
		ll y = (n - m);
		ll ans = 1;
		if(n%2 != m %2) {
			printf("0\n");
			continue;
		}
		if( (x%2==0 && y%2==0) || (x%2==1 && y%2==1)) {
			if(x > y) {
				for(ll i = y + 2; i <= x; i += 2) {
					ans *= i;
					ans %= mod;
				}
			} else {
				for(ll i = x + 2; i <= y; i += 2) {
					ans = ans*inv(i,mod);
					ans %= mod;
				}
			}
		} else {
			for(ll i = (x&1)?1:0; i <= x; i += 2) {
				ans *= i;
				ans %= mod;
			}
			for(ll i = (y&1)?1:0; i <= y; i += 2) {
				ans = ans*inv(i, mod);
				ans %= mod;
			}
		}
		ans = (ans*n)%mod;
		for(ll i = 1; i <= m; i ++) {
			ans = ans*inv(i,mod);
			ans %= mod;
		}
		ll kk = (n-m)/2;
		if(kk %2 == 1) ans *= -1;
		while(ans < 0) ans += mod;
		printf("%lld\n",ans%mod);
	}
	return 0;
}