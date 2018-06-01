#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 55;
int dp[N*10][N*10][2];
int a[N], w[N], n, m;
int main() {
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d",&w[i],&a[i]);
        a[i] += a[i-1];
    }
    memset(dp, INF, sizeof(dp));
    dp[m][m][0]=dp[m][m][1]=0;
    for(int j = m; j <= n; j ++)
        for(int i = j-1; i; i --) {
            dp[i][j][0] = min(dp[i+1][j][0] + (a[n]-(a[j]-a[i])) * (w[i+1]-w[i]),
                        dp[i+1][j][1]+(a[n]-(a[j]-a[i])) * (w[j]-w[i]));
            dp[i][j][1] = min(dp[i][j-1][1]+(a[n]-(a[j-1]-a[i-1])) * (w[j]-w[j-1]),
                        dp[i][j-1][0]+(a[n]-(a[j-1]-a[i-1])) * (w[j]-w[i]));
    }
    printf("%d\n",min(dp[1][n][0],dp[1][n][1]));
    return 0;
}
