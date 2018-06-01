#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 3410;
int w[N],d[N];
int dp[12881];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0; i < n; i ++)scanf("%d %d",&w[i],&d[i]);
	for(int i = 0; i < n; i ++){
		for(int j = m; j >= w[i]; j--){
			dp[j] = max(dp[j],dp[j-w[i]]+d[i]);
		}
	}
	printf("%d\n",dp[m]);
	return 0;
}