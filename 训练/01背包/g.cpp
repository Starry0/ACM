#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[110][110];//忍耐度为i杀j个怪得到的最大经验
int main(){
	int n,m,k,s,a,b;
	while(scanf("%d %d %d %d",&n,&m,&k,&s)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int l = 0; l < k; l ++){
			scanf("%d %d",&a,&b);
			for(int i = b; i <= m; i ++){
				for(int j = 1; j <= s; j ++){
					dp[i][j] = max(dp[i][j],dp[i-b][j-1]+a);
				}
			}
			
		}
		if(dp[m][s] < n)printf("-1\n");
		else{
			int Min = 0;
			for(int i = 0; i <= m; i ++){
				for(int j = 0; j <= s; j ++){
					if(dp[i][j] >= n){
						//printf("%d %d   :%d\n",i,j,dp[i][j])
						Min = i;
						goto tt;
					}
				}
			}
			tt:printf("%d\n",m-Min);
		}
	}
	return 0;
}