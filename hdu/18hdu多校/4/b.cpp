#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
const int N = 1e5+10;
struct mo{
	int n, k,id;
}q[N];
ll Be[N], fac[N], inv[N], res[N], unit, t;
vector<mo> lst[N];
ll pow_mod(ll x, ll n){  
    ll res=1;  
    while(n>0){  
        if(n&1)res=res*x%mod;  
        x=x*x%mod;  
        n>>=1;  
    }  
    return res;  
}
bool cmp(mo a, mo b) {
	return a.n < b.n;
}
ll C(int a, int b) {
	return fac[a] * inv[b] % mod * inv[a-b] % mod;
}
int main() {
	int mx = 100000; unit = sqrt(mx);
	fac[0] = 1;for(int i = 1; i <= mx; i ++) fac[i] = fac[i-1] * i %mod, Be[i] = i/unit + 1;
	inv[mx] = pow_mod(fac[mx], mod-2); for(int i = mx-1; i >= 0; i --) inv[i] = inv[i+1] *(i+1) % mod;
	scanf("%lld", &t);
	for(int i = 1; i <= t; i ++) {
		scanf("%d%d",&q[i].n,&q[i].k), q[i].id = i;
		lst[Be[q[i].k]].push_back(q[i]);
	}
	for(int i = 1; i <= mx; i ++) {
		if(lst[i].size()) {
			sort(lst[i].begin(),lst[i].end(), cmp);
			ll val = 0, in = lst[i][0].n, ik = -1;
			for(auto e : lst[i]) {
				while(in < e.n) val = (val + val + mod - C(in++, ik)) % mod;
				while(ik < e.k) val = (val + C(in, ++ik)) % mod;
				while(ik > e.k) val = (val + mod - C(in, ik--)) % mod;
				res[e.id] = val;				
			}
		}
	}
	for(int i = 1; i <= t; i ++) printf("%lld\n",res[i]);
	return 0;
}