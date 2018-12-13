#include <bits/stdc++.h>
#define ll long long
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

ll phi(ll x){
    ll ans = x;
    for(ll i = 2; i*i <= x; i++){
        if(x % i == 0){
            ans = ans / i * (i-1);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) ans = ans / x * (x-1);
    return ans;
}
int main() {
    ll n;
    while(cin >> n) {
        if(n == 1) {
            printf("0\n");
            continue;
        }
        ll ans = (((n%mod)*((n+1)%mod))%mod)*pow_mod(2,mod-2)%mod-(((n%mod)*(phi(n)%mod))%mod)*pow_mod(2,mod-2)%mod;
        ans %= mod;
        printf("%lld\n",(ans+mod)%mod);
    }
    return 0;
}
