#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll a[N];
int main() {
    ll n, d;
    scanf("%lld%lld",&n,&d);
    for(int i = 0; i < n; i ++) scanf("%lld",&a[i]);
    a[n] = 1e10;
    ll ans = 0;
    for(int i = 0; i < n-2; i ++) {
        ll tmp = a[i] + d;
        int index = upper_bound(a,a+n,tmp) - a -1;
        // cout << index << endl;
        ll cnt = index - i;
        if(cnt > 1) {
            ans += (cnt-1)*cnt/2;
        }
    }
    cout << ans << endl;
    return 0;
}
