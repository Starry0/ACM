#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10010;
ll p[N], n;
int main() {
    cin >> n;
    ll ans = 0, ans1 = 0;
    for(int i = 0; i < n; i ++) cin >> p[i];
    sort(p, p+n);
    for(int i = 0; i < n; i ++) {
        ans += abs(p[i]-p[n/2]);
    }
    cout << ans << endl;
    return 0;
}
