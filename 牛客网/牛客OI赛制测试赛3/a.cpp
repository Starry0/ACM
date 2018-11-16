#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
const ll mod = 1e9+7;
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
	ll n, k;
	cin >> n >> k;
	if(k > 8 || k < -9) return 0*printf("0\n");
	else {
		ll x = pow_mod(10, n-2);
		if(k >= 0) printf("%lld\n",x*(9-(1+k)+1)%mod);
		else printf("%lld\n",x*(0-(-9-k)+1)%mod);
	}
	return 0;
}
