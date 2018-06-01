#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1010;
int dp[N], a[N], n;
int main(){
    while(scanf("%d",&n)&&n) {
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            dp[i] = a[i];
            for(int j = 0; j < i; j ++) {
                if(a[i] > a[j]) dp[i] = max(dp[i],dp[j]+a[i]);
            }
            ans = max(dp[i],ans);
        }
        printf("%d\n",ans);
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
    }
    return 0;
}
