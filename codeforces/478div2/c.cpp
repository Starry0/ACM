#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
ll a[N], n, q, sum[N];
int main() {
    cin >> n >> q >> a[0];
    for(int i = 1; i < n; i ++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    ll id = 0, ans = 0;
    while(q--) {
        ll k;
        cin >> k;
        ans += k;
        id = upper_bound(a,a+n,ans)-a;
        if(id == n) id = 0, ans = 0;
        cout << n - id << endl;
    }
    return 0;
}
