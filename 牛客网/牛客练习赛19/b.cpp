#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
int main() {
    ll t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if(n > k) {
            printf("1/1\n");
            continue;
        }
        ll sum = 1;
        for(int i = 1; i <= n; i ++) sum *= k;
        ll a = 1;
        for(ll i = k-n+1; i <= k; i ++) a *= i;
        for(ll i = 1; i <= n; i ++) a /= i;
        a = sum - a;
        ll tmp = __gcd(a,sum);
        printf("%lld/%lld\n",a/tmp,sum/tmp);
    }
    return 0;
}
