#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    ll a,b;
    scanf("%d",&n);
    while(n--) {
        scanf("%lld%lld",&a,&b);
        ll x = cbrt(a*b+0.5);
        ll xx = a/x, yy = b/x;
        if(xx*yy*xx == a && xx*yy*yy == b)puts("Yes");
        else puts("No");
    }
    return 0;
}
