#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
const ll mod = 1e9+7;
ll prime[N], fac[N], res[N], pos;
bool vis[N];
ll add(ll x) {
	int tmp = pos;
	for(int i = 0; i < tmp; ++ i) {
		fac[pos] = fac[i]*x, res[pos] = res[i]+1;
		pos++;
	}
}
int main() {
	ll n, m;
	ll x = 166666668;
	for(int i = 2; i < N; i ++) {
		if(!vis[i]) {
			for(int j = i+i; j < N; j += i) vis[j] = 1;
		}
	}
	for(int i = 2; i < N; i ++) if(!vis[i]) prime[cnt++] = i;
	while(scanf("%d%d", &n, &m) != EOF) {
		int tmp = m; pos = 1;
		fac[0] = 1;
		res[0] = 0;
		for(int i = 0; i < cnt && prime[i]*prime[i] <= m; i ++) {
			if(!(tmp%prime[i])) {
				while(prime[i] != 1 && !(tmp%prime[i]))
					tmp /= prime[i];
				add(prime[i]);
			}
		}
		if(tmp > 1) add(tmp);
		ll ANS = 0;
		for(int i = 0; i < pos; ++ i) {
			ll number = n/fac[i];
			ll ans1 = (x*number%mod)*((number+1)*(2*number+1)%mod)%mod;
			ll ans2 = (number*(number+1)/2)%mod;
			ll ans = (ans1*fac[i]%mod)*fac[i]%mod+ans2*fac[i]%mod;
			if(res[i]%2) ANS = ((ANS-ans)%mod+mod)%mod;
			else ANS = (ANS+ans)%mod;
		}
		printf("%lld\n",ANS%mod);
	}
	return 0;
}