#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, max, k, last;
    cin >> n >> a >> max >> k >> last;
    int cnt = 0, ans = 0;
    while(true) {
        cnt += a;
        ans ++;
        if(cnt >= n) break;
        cnt -= last;
        a = min(max,a+k);
    }
    cout << ans << endl;
    return 0;
}
