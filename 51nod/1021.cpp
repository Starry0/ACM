#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define INF 0x3f3f3f3f
int dp[110][110], sum[110];
int main() {
    int n, num;
    cin>>n;
    for(int i = 0; i < n; i ++)
        cin>>num,sum[i+1] = sum[i]+num;
    for(int l = 2; l <= n; l ++) {
        for(int s = 1; s <= n-l+1; s ++) {
            int e = s+l-1;
            int Min = INF;
            for(int k = s; k < e; k ++){
                if(dp[s][k]+dp[k+1][e]+sum[e]-sum[s-1] < Min)
                    Min = dp[s][k]+dp[k+1][e]+sum[e]-sum[s-1];
            }
            dp[s][e] = Min;
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
