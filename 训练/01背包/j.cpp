#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[110], c[110],n,m;
int dp[100010]; 

int main(){
	while(scanf("%d %d",&n,&m)&&n){
		memset(dp,-1,sizeof(dp));
		for(int i = 0; i < n; i ++)scanf("%d",&a[i]);
		for(int i = 0; i < n; i ++)scanf("%d",&c[i]);
		dp[0]=0;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j <= m; j ++){
				if(dp[j] >= 0)dp[j] = c[i];
				else if(j < a[i] || dp[j-a[i]] <=0)dp[j] = -1;
				else dp[j] = dp[j-a[i]]-1;
			}
		}
		int ans = count_if(dp+1,dp+1+m,bind2nd(greater_equal<int>(),0));
		printf("%d\n",ans);
	}
	return 0;
}