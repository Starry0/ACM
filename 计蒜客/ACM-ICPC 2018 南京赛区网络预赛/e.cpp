#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N = (1<<20)+10;
ll a[N], s[N], b[N], c[N], dp[N];
void init() {
    for(int i = 0; i < N; i ++) {
        int cnt = i;
        while(cnt) {
            if(cnt&1) c[i] ++;
            cnt >>= 1;
        }
    }
}
int main() {
    int n, x, le;
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%lld%lld%d",&a[i], &b[i], &le);
        s[i] = 0;
        for(int j = 0; j < le; j ++) {
            scanf("%d", &x);
            x--;
            s[i] += (1<<x);
        }
    }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for(int i = 0; i < n; i ++) if(s[i] == 0) dp[1<<i] = a[i]+b[i];
    for(int i = 0; i < (1<<n); i ++) {
        for(int j = 0; j < n; j ++) {
            if((i&(1<<j)) && (i^s[j])==i-s[j] && dp[i^(1<<j)] != -1) {
                dp[i] = max(dp[i], dp[i^(1<<j)]+c[i]*a[j]+b[j]);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}