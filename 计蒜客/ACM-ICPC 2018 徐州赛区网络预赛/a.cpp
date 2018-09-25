#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
const int N = 1e6+10;
ll dp[N];
ll pow_mod(ll x, ll n){  
    ll res=1;  
    while(n>0){  
        if(n&1)res=res*x%mod;  
        x=x*x%mod;  
        n>>=1;  
    }  
    return res;  
}
int main() {
	int t, n, k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d", &n, &k);
		dp[1] = pow_mod(2,k);
		dp[2] = ((pow_mod(2,k)-1)%mod)*pow_mod(2,k)%mod;
		for(int i = 3; i <= n; i ++) {
			ll ans1 = dp[i-2]*(pow_mod(2,k)-1)%mod;
			ll ans2 = (dp[i-1]-pow_mod(2,k)+mod)%mod*(pow_mod(2,k)-2)%mod;
			dp[i] = ((ans1+ans2)%mod+mod)%mod;
		}
		printf("%lld\n",dp[n]);
	}	
	return 0;
}