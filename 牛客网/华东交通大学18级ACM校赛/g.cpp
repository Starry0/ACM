#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 20;
ll a[N], dp[N][N][N], l, r;

bool ok(ll val, int sum) {
    return (val%7==0)&&(sum%7==0);
}
ll dfs(int pos, int sum, ll val, bool flag) {
    if(pos == -1) return ok(val, sum);
    if(!flag && dp[pos][sum][val] != -1) return dp[pos][sum][val];
    int top = flag? a[pos]: 9;
    ll ans = 0;
    for(int i = 0; i <= top; i ++) {
        ans += dfs(pos-1,(sum+i)%7, (val*10+i)%7, flag&&i==top);
    }
    if(!flag) dp[pos][sum][val] = ans;
    return ans;
}

ll f(ll m) {
    int cnt = 0;
    while(m) {
        a[cnt++] = m%10;
        m /= 10;
    }
    return dfs(cnt-1, 0, 0, 1);
}
int main() {
    memset(dp, -1, sizeof(dp));
    while(cin >> l >> r) {
        if(l == 0 && r == 0) break;
        printf("%lld\n",f(r)-f(l-1));
    }
    return 0;
}
