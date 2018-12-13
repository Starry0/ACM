#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int a[N], n, k, x;
bool cmp(int x, int y) { return x > y;}
bool ok(int m) {
    int ans = 0;
    for(int i = 0; i < N; i ++) if(a[i])ans += a[i]/m;
    return ans >= k;
}
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> x;
        a[x]++;
    }
    int l = 1, r = n/k, MAX = 0;
    while (l <= r) {
        int m = (l+r) >> 1;
        if(ok(m)) {
            MAX = max(MAX, m);
            l = m + 1;
        } else r = m-1;
    }
    int ans = 0;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < a[i]/MAX; j ++) {
            if(ans == k) break;
            printf("%d%c",i," \n"[ans==k-1]);
            ans ++;
        }
    }
    return 0;
}
