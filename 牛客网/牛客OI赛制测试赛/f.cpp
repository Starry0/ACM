#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
const ll md = 1e9+6;
const int N = 1010;
ll a[N], c[N][N];
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
	memset(c, 0, sizeof(c));
    c[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % md;
        }
    }
    int t, n, k;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i ++) cin >> a[i];
		sort(a+1,a+1+n);
		ll res = 1;
		for(int i = 1; i <= n; i ++) {
			ll ans = ((c[n-1][k-1] - c[i-1][k-1] - c[n-i][k-1])%md + md) % md;
			res = res*pow_mod(a[i],ans)%mod;
		}
		printf("%lld\n",res);
	}
	return 0;
}