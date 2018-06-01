#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int Inf = 1<<25;
int a[7], dp[2050];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);
		for(int i = 0; i < 2050; i ++)dp[i] = Inf;
		dp[0] = 0;
		for(int i = 1; i <= 6; i ++){
			for(int j = a[i]; j < 2050; j ++){
				dp[j] = min(dp[j],dp[j-a[i]]+1);
			}
		}
		//for(int i = 1; i <= 100; i ++)printf("%d  %d\n",i,dp[i]);
		int Max = -1,sum = 0;
		for(int i = 1; i <= 100; i ++){
			int ans = dp[i];
			for(int j = i+1; j < 2050; j ++){
				ans = min(ans,dp[j]+dp[j-i]);
			}
			Max = max(Max,ans);
			sum += ans;
		}
		printf("%.2f %d\n",1.0*sum/100,Max);
	}
	return 0;
}