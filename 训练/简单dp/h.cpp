#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 50000;
int a[N],dp[N];
int main() {
    int t, n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i = 0; i < n; i ++)
            scanf("%d",&a[i]), dp[i] = INF;
        for(int i = 0; i < n; i ++)
            *lower_bound(dp,dp+n,a[i]) = a[i];
        int ans = lower_bound(dp,dp+n,INF) - dp;
        printf("%d\n",ans);
    }
    return 0;
}
