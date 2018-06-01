#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll r[N], a[N];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> r[i];
    ll ans = 0, cnt = 1;
    sort(r+1,r+1+n);
    for(int i = 1; i <= n; i += 2) {
        a[i] = r[cnt++];
    }
    for(int i = n+(n%2?-1:0); i >= 1; i -= 2) {
        a[i] = r[cnt++];
    }
    for(int i = 2; i <= n; i ++) ans += abs(a[i]-a[i-1]);
    ans += abs(a[1]-a[n]);
    cout << ans << endl;
    return 0;
}
