#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[10010];
int main(){
	int n,W;
	scanf("%d %d",&n,&W);
	for(int i = 0; i < n; i ++){
		int w,p;
		scanf("%d %d",&w,&p);
		for(int j = W; j >= w; j --){
			dp[j] = max(dp[j],dp[j-w]+p);
		}
	}
	printf("%d\n",dp[W]);
	return 0;
}