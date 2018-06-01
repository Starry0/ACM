#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
ll n, w, a[N];
ll max(ll x, ll y) {
    return x > y ? x: y;
}
int main() {
    cin >> n >> w >> a[0];
    for(int i = 1; i < n; i ++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    ll MIN = 1e12, MAX = -1e12;
    for(int i = 0; i < n; i ++) {
        MIN = min(MIN, a[i]);
        MAX = max(MAX, a[i]);
    }
    // cout << MIN << ' ' << MAX << endl;
    if(MIN < 0 && MAX < 0) {
        cout << max(0,w + MIN+1) << endl;
    } else if(MAX >= 0 && MIN < 0) {
        MAX -= MIN;
        cout << max(0,w - MAX + 1) << endl;
    } else if(MAX >= 0 && MIN >= 0) {
        cout << max(0, w - MAX + 1) << endl;
    }
    return 0;
}
