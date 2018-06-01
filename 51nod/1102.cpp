#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4+10;
int a[N], l[N], r[N];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        l[i] = i; r[i] = i;
        while(a[l[i]-1] >= a[i]) l[i]--;
        while(a[r[i]+1] >= a[i]) r[i]++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans = max(ans,1LL*a[i]*(r[i]-l[i]+1));
    }
    cout << ans << endl;
    return 0;
}
