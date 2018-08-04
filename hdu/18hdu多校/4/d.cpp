#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 110;
ll a[N], t;
int main() {
    ll t, n, m, x;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i ++) cin >> x >> a[i], a[i]++;
        sort(a,a+n);
        ll ans = 0, cnt = 1;
        for(int i = 0; i < n; i ++) {
            if(a[i]*cnt <= m) {
                ans++;
                cnt *= a[i];
            } else break;
        }
        cout << ans << endl;
    }
    return 0;
}