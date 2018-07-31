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
	int t;
	cin >> t;
	while(t--) {
		ll n, ans;
		cin >> n;
		n%=mod;
		if(n == 1) ans = 1; 
		else ans = (n*(n+1))%mod*pow_mod(2,n-2)%mod;
		cout << ans << endl;
	}
	return 0;
}