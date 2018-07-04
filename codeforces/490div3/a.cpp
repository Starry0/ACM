#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int n, k;
int a[N];
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i ++) cin >> a[i];
    int i, ans = 0;
    for(i = 0; i < n; i ++) {
        if(a[i] > k) break;
        ans ++;
    }
    for(int j = n-1; j > i; j --) {
        if(a[j] > k) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
