//
// Created by starry on 2019/8/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+10;
const ll mod = 1e9+7;

ll __pow(ll a, ll b) {
    ll ans = a;
    for(ll i = 1; i < b; i ++) ans *= a;
    return ans;
}

ll fun(ll n, ll a, ll b) {
    ll result = 0;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= i; j ++) {
            if(__gcd(i, j) == 1) {
                result = (result + __gcd(__pow(i, a)-__pow(j,a), __pow(i,b)-__pow(j,b))) % mod;
            }
        }
    }
    return result;
}

int main() {
    for(ll n = 7; n <= 7; n ++) {
        for(ll a = 1; a < 20; a ++) {
            for(ll b = 1; b < 20; b ++) {
                printf("%lld ",fun(n,a,b));
            }
            printf("\n");
        }
    }

    return 0;
}