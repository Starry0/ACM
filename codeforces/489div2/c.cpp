#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;

ll pow_mod(ll x, ll n) {
    ll ans = 1;
    while(n) {
        if(n&1) ans = ans*x%mod;
        x = x*x%mod;
        n /= 2;
    }
    return ans;
}

int main() {
    ll x, k;
    cin >> x >> k;
    if(k == 0) return 0*printf("%lld\n",x*2%mod);
    if(x == 0) return 0*printf("0\n");
    cout << ((2*x-1)%mod*pow_mod(2,k)+1)%mod << endl;
    return 0;
}
// 2*(x^k-2^k)+1
// 2 1
// 3 4
//
// 3 2
// 5 6
// 9 10 11 12
// 17 18 19 20 21 22 23 24
