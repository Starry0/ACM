#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 15;
ll qmul(ll a,ll p,ll m){
    ll tmp = 0;
    while(p){
        if(1&p) tmp = (tmp+a)%m;
        a = (a+a)%m;
        p>>=1;
    }
    return tmp;
}
void exgcd(ll a,ll b,ll &x,ll &y,ll &d){
    if(!b) d=a,x = 1,y=0;
    else exgcd(b,a%b,y,x,d),y-=(a/b)*x;
}
ll inv(ll a,ll p){
    ll x,y,d;
    exgcd(a,p,x,y,d);
    return d==1?(x+p)%p:-1;
}
ll fat(ll x,ll p){
    ll ans = 1;
    for( int i = 2 ; i <= x ; i ++ ) ans = ( ans * i ) % p;
    return ans;
}
ll c(ll n,ll m,ll p){
    if (m < 0 || m > n) return 0; 
    return fat(n,p)*inv(fat(m,p),p)%p*inv(fat(n-m,p),p)%p;
}
ll crt(ll *a,ll *m,int n){
    ll M = 1,res = 0;
    for( int i = 0 ; i < n ; i++ ) M*=m[i];
    for( int i = 0 ; i < n ; i++ ){
        ll w = M/m[i];
        res = (res+qmul(w*inv(w,m[i]),a[i],M))%M;
    }
    return (res+M)%M;
}
ll Lucas(ll n,ll m,ll p){
    return m?Lucas(n/p,m/p,p)*c(n%p,m%p,p)%p:1;
}
int main() {
	ll a[N], p[N];
	ll t, n, m, k;
	cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		for(int i = 0; i < k; i ++) {
			cin >> p[i];
			a[i] = Lucas(n, m, p[i]);
		}
		printf("%lld\n",crt(a, p, k));
	}
	return 0;
}