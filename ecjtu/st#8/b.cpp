#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int v[1010];
int dp[1010];
int main(){
    int n,m,p;
    while(scanf("%d",&n)&&n){
        for(int i = 0; i < n; i ++)scanf("%d",&v[i]);
        scanf("%d",&m);
        sort(v,v+n);
        for(int i = 0; i < n-1; i ++){
            for(int k = m-5; k >= v[i]; k--){
                dp[k] = max(dp[k],dp[k-v[i]]+v[i]);
            }
        }
        if(m < 5)printf("%d\n",m);
        else printf("%d\n",m-dp[m-5]-v[n-1]);
        memset(dp,0,sizeof(dp));
        memset(v,0,sizeof(v));
    }
    return 0;
}
