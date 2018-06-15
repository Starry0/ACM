#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
ll t, n, m, k, p;
ll a[N], b[N];
ll pow_mod(ll x, ll n) {
    ll y = 1;
    while(n) {
        if(n&1) y = y*x%p;
        x = x*x%p;
        n >>= 1;
    }
    return y;
}
void init() {
    a[1] = 1;
    for(ll i = 2; i <= k; i ++) a[i] = (a[i-1])*i%p;
    for(ll i = 1; i <= k; i ++) {
        b[i] = pow_mod(a[i],p-2);
    }
}
ll C(ll x, ll y) {
    return (a[x]*b[y])%p*b[y]%p;
}
int main() {
    cin >> t;
    while(t--) {
        ll ans = 0;
        cin >> n >> m >> k >> p;
        init();
        ll x = k/2;
        printf("\n");
        for(ll i = x; i >= 0; i --) {
            ll j = k - i*2;
            printf("%lld %lld\n", j,i);
            ans += C(m, i) % p * C(n, j) % p;
        }
        cout << ans << endl;
    }
    return 0;
}
