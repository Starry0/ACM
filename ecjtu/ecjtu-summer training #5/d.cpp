#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const int MAX = 110;
int tree[MAX][MAX],n;
int dp[MAX][MAX];
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(tree,0,sizeof(tree));
		memset(dp,0,sizeof(dp));
		int k = 1;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= i; j ++){
				scanf("%d",&tree[i][j]);
			}
		}
		for(int i = n; i > 0; i--){
			for(int j = 1; j <= i; j ++){
				if(i == n)dp[i][j] = tree[i][j];
				else dp[i][j] = max(tree[i][j]+dp[i+1][j],tree[i][j]+dp[i+1][j+1]);
			}
		}
		printf("%d\n",dp[1][1]);
	}
	return 0;
}