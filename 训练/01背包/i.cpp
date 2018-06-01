#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[7], dp[21*20010];
int main(){
	int k = 1;
	while(scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6])!=EOF){
		if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0)break;
		memset(dp,-1,sizeof(dp));
		int sum = a[1]+2*a[2]+3*a[3]+4*a[4]+5*a[5]+6*a[6];
		if(sum&1){
			printf("Collection #%d:\nCan't be divided.\n\n",k++);
			continue;
		}
		dp[0]=0;
		for(int i = 1; i <= 6; i ++){
			for(int j = 0; j <= sum/2; j ++){
				if(a[i]==0)continue;
				if(dp[j] >= 0)dp[j]=a[i];
				else if(j < i || dp[j-i] < 0)dp[j] = -1;
				else dp[j] = dp[j-i]-1;	
			}
		}
		//printf("++++%d+++%d\n",sum,dp[sum/2]);
		if(dp[sum/2] >= 0)printf("Collection #%d:\nCan be divided.\n\n",k++);
		else printf("Collection #%d:\nCan't be divided.\n\n",k++);
	}
	return 0;
}