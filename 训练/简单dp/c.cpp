#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[550], b[550], dp[550][550];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n, m;
        scanf("%d",&n);
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int i = 0; i < m; i ++) scanf("%d",&b[i]);
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j] + (b[j] > b[j-1]);
                else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
        cout << dp[n][m] << endl;
        if(t)printf("\n");
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    return 0;
}
