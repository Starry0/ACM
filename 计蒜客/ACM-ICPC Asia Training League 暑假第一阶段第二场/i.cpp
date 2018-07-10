#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
pair<ll,ll> p[50];
ll f[50];
ll extgcd(ll a, ll b, ll &x, ll &y){
    ll d = a;
    if(b != 0){
        d = extgcd(b,a%b,y,x);
        y -= (a/b)*x;
    }else{
        x = 1; y = 0;
    }
    return d;
}
int main() {
	int t, n;
	f[1] = f[2] = 1;
	for(int i = 3; i < 50; i ++) f[i] = f[i-1] + f[i-2];
	p[1].first = 1, p[1].second = 0;
	for(int i = 2; i <= 50; i ++) {
		p[i].first = f[i-2], p[i].second = f[i-1];
	}
	cin >> t;
	while(t--) {
		cin >> n;
		ll a = 1e13, b = 1e13;
		ll aa, bb;
		for(int i = 49; i >= 3; i --) {
			ll x = p[i].first, y = p[i].second;
			if(x + y > n) continue;
			if(n%__gcd(x,y) != 0) continue;
			extgcd(x,y,aa,bb);
			aa *= n;
			bb *= n;
			ll cnt = (bb-aa)/(x+y);
			aa += cnt*y;
			bb -= cnt*x;
			if(aa > bb) {
				aa -= y;
				bb += x;
			}
			if(aa > bb || aa < 1) continue;
			if(bb < b) {
				b = bb;
				a = aa;
			} else if(bb == b) {
				a = aa;
			}
		}
		cout << a << ' ' << b << endl;
	}
}