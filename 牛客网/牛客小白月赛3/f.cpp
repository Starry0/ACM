#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll x, ll y) {
    return y?gcd(y,x%y):x;
}
int main() {
    ll a, b, c, d, x, y;
    while(cin >> a >> b >> c >> d) {
        ll l = max(a,c);
        ll r = min(b,d);
        if( l > r) {
            printf("0/1\n");
            continue;
        }
        y = (b-a+1)*(d-c+1);
        x = (r-l+1);
        ll tmp = gcd(x,y);
        printf("%lld/%lld\n",x/tmp,y/tmp);
    }
    return 0;
}
