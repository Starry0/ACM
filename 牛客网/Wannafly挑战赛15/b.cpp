#include <bits/stdc++.h>
using namespace std;
int a[6], n, x, ans;
int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> x;
        a[x]++;
    }
    ans = a[5]+a[4]+a[3];
    a[1] = max(0,a[1]-a[4]);
    x = a[3]-a[2];
    a[2] = max(0,a[2]-a[3]);
    if(x > 0) {
        a[1] = max(0,a[1]-x*2);
    }
    ans += a[2]/2;
    a[1] = max(0,a[1]-a[2]/2);
    if(a[2]%2) {
        ans++;
        a[1] = max(0,a[1]-3);
    }
    ans += a[1]/5;
    if(a[1]%5)ans++;
    cout << ans << endl;
    return 0;
}
