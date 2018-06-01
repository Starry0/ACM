#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[50010];
int main(){
	int n,W;
	scanf("%d %d",&n,&W);
	for(int i = 0; i < n; i ++){
		int w,p,c;
		scanf("%d %d %d",&w,&p,&c);
		for(int k = 1,flag = 0;; k*=2){
			if(k*2 > c){
				k = c-k+1;
				flag = 1;
			}
			for(int j = W; j >= k*w; j--){
				dp[j] = max(dp[j],dp[j-k*w]+k*p);
			}
			if(flag)break;
		}
	}
	printf("%d\n",dp[W]);
	return 0;
}