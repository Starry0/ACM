#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 550;
int a[N][N], dp[N][N], vis[N][N];
int main() {
    int n, m;
    cin >> m >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(dp[i][j-1] > dp[i-1][j]) {
                dp[i][j] = a[i][j] + dp[i][j-1];
                vis[i][j-1] = 1;
            } else {
                dp[i][j] = a[i][j] + dp[i-1][j];
                vis[i-1][j] = 1;
            }
        }
    }
    for(int i = n; i >= 1; i --) {
        for(int j = m; j >= 1; j --) {
            if(dp[i][j+1] > dp[i+1][j]) {
                dp[i][j] += dp[i][j+1] + vis[i][j] ?a[i][j]:0;
            }else dp[i][j] += dp[i+1][j] + vis[i][j] ?a[i][j]:0;
        }
    }
    printf("%d\n",dp[1][1]);
    return 0;
}
