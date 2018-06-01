#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
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
int main() {
    ll n, m, p = 1, ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];
    for(int i = 1; i <= n; i ++) {
        if(a[i]&&b[i]) {
            if(a[i] > b[i]) {
                ans += p;
                ans %= mod;
                break;
            } else if(a[i] < b[i])break;
        } else if(a[i]&&!b[i]){
            ans += p*(a[i]-1LL)%mod*pow_mod(m,mod-2);
            ans %= mod;
            p *= pow_mod(m,mod-2);
            p %= mod;
        } else if(!a[i]&&b[i]) {
            ans += p*(m-b[i])%mod*pow_mod(m,mod-2);
            ans %= mod;
            p *= pow_mod(m,mod-2);
            p %= mod;
        } else{
            ans += p*(m-1)%mod*pow_mod(2*m,mod-2);
            ans %= mod;
            p *= pow_mod(m,mod-2);
            p %= mod;
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
