#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1e5+10;
ll a[N], tot;

ll mod_mul(ll a, ll b, ll n){
    ll cnt = 0LL;
    while(b){
        if(b&1LL) cnt = (cnt+a)%n;
        a=(a+a)%n;
        b >>= 1LL;
    }
    return cnt;
}
ll mod_exp(ll a, ll b, ll n){
    ll res = 1LL;
    while(b){
        if(b&1LL) res = mod_mul(res,a,n);
        a = mod_mul(a,a,n);
        b >>= 1LL;
    }
    return res;
}
bool ispirme(ll n){
	int respat = 5;
    if(n==2LL || n==3LL || n==5LL || n==7LL || n==11LL) return true;
    if(n==1 || !(n%2) || !(n%3) || !(n%5) || !(n%7) || !(n%11)) return false;
    
    int k = 0;
    ll d = n-1; 
    
    while(!(d&1LL)){
        k++; d >>= 1LL;
    }
    srand((ll)time(0));
    for(int i = 0; i < respat; i ++) {
        ll a = rand()%(n-2)+2;    
        ll x = mod_exp(a,d,n);
        ll y = 0LL;
        for(int j = 0; j < k; j ++){
            y = mod_mul(x,x,n);
            if(1LL==y && 1LL!=x && n-1LL!=x)return false; 
            x = y;
        }
        if(1LL != y) return false;  
    }
    return true;
}

ll gcd(ll a, ll b) {
    if(a == 0) return 1;
    if(a <  0) return gcd(-a,b);
    while(b) {
        ll t = a%b;
        a = b;
        b = t;
    }
    return a;
}

ll Pollard_rho(ll x, ll c) {
    ll i =1, k=2;
    ll x0=rand()%x;
    ll y = x0;
    while(1)
    {
        i++;
        x0 = (mod_mul(x0,x0,x)+c)%x;
        ll d = gcd(y-x0,x);
        if(d!=1 && d!=x) return d;
        if(y == x0) return x;
        if(i == k) {y=x0; k+=k;}
    }
}

void findfac(ll n) {
	if(n <= 1) return ;
    if(ispirme(n))  {
        a[tot++] = n;
        return;
    }
    ll p = n;
    while(p >= n)
        p = Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}

int main() {
	ll t, n, ans = 1, cnt = 0;
	scanf("%lld", &n);
	if(ispirme(n)) printf("2\n");
	else {
		findfac(n);
		for(int i = 0; i < tot; i ++) {
			ll cnt = 0;
			// printf("%d\n",a[i]);
			while(n > 0 && n%a[i] == 0) {
				cnt++;
				n /= a[i];
			}
			if(cnt) ans *= (cnt+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
