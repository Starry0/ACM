//for i:n : C(i*2,i)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
const int N = 2e6+10;
ll a[N], b[N];
ll n, ans = 0;
ll pow_mod(ll x, ll n) {
    ll y = 1;
    while(n) {
        if(n&1) y = y*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return y;
}
void init() {
    a[1] = 1;
    for(ll i = 2; i <= 2*n; i ++) a[i] = (a[i-1])*i%mod;
    for(ll i = 1; i <= n; i ++) {
        b[i] = pow_mod(a[i],mod-2);
    }
}
ll C(int x, int y) {
    return (a[x]*b[y])%mod*b[y]%mod;
}
int main() {
    cin >> n;
    init();
    for(int i = 1; i <= n; i ++) {
        ans = (ans + C(i*2,i)) % mod;
    }
    cout << ans << endl;
    return 0;
}
