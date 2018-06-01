#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int v[5500];
int dp[250100];
int main(){
	int n;
	while(scanf("%d",&n)&&n>0){
		int sum = 0,a,b,k=0;
		memset(dp,0,sizeof(dp));
		memset(v,0,sizeof(v));
		for(int i = 0; i < n; i ++){
			scanf("%d %d",&a,&b);
			sum += a*b;
			while(b--)v[k++]=a;
		}
		for(int i = 0; i < k; i ++){
			for(int j = sum/2; j >= v[i]; j --){
				dp[j] = max(dp[j],dp[j-v[i]]+v[i]);
			}
		}
		printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
	}
	return 0;
}