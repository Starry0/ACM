#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll x, ll y) {
    return y?gcd(y,x%y):x;
}
int main() {
    ll x, y, l ,r, ans = 0;
    cin >> l >> r >> x >> y;
    for(ll i = x; i*i <= x*y; i += x) {
        if(x*y%i == 0) {
            ll j = x*y/i;
            if(l <= i && i <= r && l <= j && j <= r)
            if(gcd(i, j) == x)
                ans += 1 + (i!=j);
        }
    }
    cout << ans << endl;
    return 0;
}
