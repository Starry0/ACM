#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2020;
ll a[N], ans[N];
ll n, k;
bool ok(ll x) {
    ll res = N;
    for(ll i = 1; i <= n; i ++) {
        ans[i] = i-1;
        for(ll j = 1; j < i; j ++) {
            if(abs(a[i]-a[j]) <= x*(i-j))
                ans[i] = min(ans[i], ans[j]+i-j-1);
        }
        res = min(res,ans[i]+n-i);
    }
    return res <= k;
}
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    ll l = 0, r = 2e9;
    while(l < r) {
        ll m = (l+r) >> 1;
        if(ok(m)) r = m;
        else l = m+1;
    }
    printf("%lld\n",r);
    return 0;
}
