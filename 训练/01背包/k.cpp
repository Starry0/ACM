#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int Inf = 1<<25;
int dp1[20010],dp2[20010],n,t;
int v[110],c[110];
void zero_or_pack(int *dp, int val, int num){
	for(int i = 20000; i >= val; i--)
		dp[i] = min(dp[i],dp[i-val]+num);
}
void comlePack(int *dp, int val){
	for(int i = val; i <= 20000; i ++)
		dp[i] = min(dp[i],dp[i-val]+1);
}
void multiPack(int *dp, int val, int num){
	if(val*num >= 20000){
		comlePack(dp,val);
		return;
	}
	int k = 1;
	while(k < num){
		zero_or_pack(dp,val*k,k);
		num -= k;
		k*=2;
	}
	zero_or_pack(dp,val*num,num);
}
int main(){
	while(scanf("%d %d",&n,&t)!=EOF){
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		for(int i = 0; i < n; i ++) scanf("%d",&v[i]);
		for(int i = 0; i < n; i ++) scanf("%d",&c[i]);
		for(int i = 0; i <= 20000; i ++) dp1[i]=dp2[i]=Inf;
		dp1[0]=dp2[0]=0;
		for(int i = 0; i < n; i ++)
			multiPack(dp1,v[i],c[i]);
		for(int i = 0; i < n; i ++)
			comlePack(dp2,v[i]);
		int ans = dp1[t];
		for(int i = t+1; i <= 20000; i ++)
			ans = min(ans,dp1[i]+dp2[i-t]);
		printf("%d\n",ans==Inf?-1:ans);
	}
	return 0;
}