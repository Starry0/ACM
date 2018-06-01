#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int p[110],w[110];
int dp[110][10010];
int main(){
	int n,ww;
	cin>>n>>ww;
	for(int i = 0; i < n; i ++){
		cin>>w[i]>>p[i];
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j <= ww; j ++){
			if(j < w[i]){
				dp[i+1][j] = dp[i][j];
			}else dp[i+1][j] = max(dp[i][j],dp[i][j-w[i]]+p[i]);
		}
	}
	printf("%d\n",dp[n][ww]);
	return 0;
}