#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
const int N = 1e5+10;
ll a[N], b[N];
ll pow_mod(ll x, ll n){  
    ll res=1;  
    while(n>0){  
        if(n&1)res=res*x%mod;  
        x=x*x%mod;  
        n>>=1;  
    }  
    return res;  
}
void init() {
	a[0] = 1;
	for(int i = 1; i < N; i ++) a[i] = (a[i-1]*i)%mod;
	b[1] = 1;
	for(int i = 1; i < N; i ++) b[i] = pow_mod(i,mod-2)%mod;
	for(int i = 2; i < N; i ++) b[i] = (b[i]*b[i-1])%mod;

}
int main() {
	init();
	ll t, n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		
	}
	return 0;
}