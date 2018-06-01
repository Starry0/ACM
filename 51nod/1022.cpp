#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const int MAX = 2005;
const int INF = 0x3f3f3f3f;
int dp[MAX][MAX], sum[MAX][MAX], s[MAX][MAX], a[MAX];

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d",&a[i]);
        a[i+n] = a[i];
    }
    for(int i = 1; i <= 2*n; i ++) {
        dp[i][i] = 0;
        s[i][i] = i;
    }
    for(int i = 1; i <= 2*n; i ++) {
        for(int j = i; j <= i+n; j ++) {
            sum[i][j] = sum[i][j-1]+a[j];
        }
    }
    for(int len = 2; len <= n; len ++) {
        for(int i = 1; i <= 2*n-len+1; i ++) {
            int j = i+len-1;
            dp[i][j] = INF;
            for(int k = s[i][j-1]; k <= s[i+1][j]; k ++){
                if(dp[i][j] > dp[i][k] + dp[k+1][j] + sum[i][j]){
                    dp[i][j] = dp[i][k] + dp[k+1][j] + sum[i][j];
                    s[i][j] = k;
                }
            }
        }
    }
    int ans = INF;
    for(int i = 1; i < n; i ++) {
        ans = min(ans,dp[i][i+n-1]);
    }
    printf("%d\n",ans);
    return 0;
}
