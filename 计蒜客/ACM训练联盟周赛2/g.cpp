#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10;
const ll mod = 1000000007;
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
	ll t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		n%=mod;
		printf("%lld\n",n*(n-3)%mod*(n*n%mod-(3*n)%mod+8+mod)%mod*pow_mod(12,mod-2)%mod);
	}
	return 0;
}