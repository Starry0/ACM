#include <iostream>
#include <stdio.h>
#define INF 0x3f3f3f3f
using namespace std;
int t, n, x;
int d[1010], dp[1010][1010];
int dis(int i, int j) {
    int ans = abs(d[i] - d[j]);
    return min(ans, 360-ans);
}
void init() {
    cin >> n;
    d[0] = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%d %d", &x, &d[i]);
    }
    dp[1][0] = dis(1, 0);
}
int slove() {
    for(int i = 2; i <= n; i ++) {
        dp[i][i-1] = INF;
        for(int j = 0; j < i-1; j ++) {
            dp[i][i-1] = min(dp[i][i-1], dp[i-1][j] + dis(i, j));
            dp[i][j] = dp[i-1][j] + dis(i,i-1);
        }
    }
    int ans = INF;
    for(int i = 0; i < n; i ++) {
        ans = min(ans, dp[n][i] + dis(i, n));
    }
    return ans;
}
int main() {
    cin >> t;
    while(t--) {
        init();
        printf("%d\n",x * 800 + n*10 + slove());
    }
    return 0;
}
