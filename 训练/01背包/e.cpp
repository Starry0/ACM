#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const int Mod = 1e9+7;
ll dp[100010];
int main(){
	int p[15] = {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i = 0; i < 13; i ++){
			for(int j = p[i]; j <= n; j ++){
				dp[j] = (dp[j]+dp[j-p[i]])%Mod;
			}
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}

