#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
ll dp[500][500];
ll ans[500];
void init(){
	dp[0][1] = dp[1][1] = dp[2][1] = 1;
	dp[2][2] = dp[3][1] = dp[3][3] = 1;
	ans[1] = 1; ans[2] = ans[3] = 2;
	for(int i = 4; i <= 250; i ++){
		ll tmp = 0;
		for(int j = 1; j <= i/2; j ++){
			if(j==1)dp[i][j] = ans[i-2];
			else{
				ll u = i-j*2;
				if(u==0)dp[i][j] = 1;
				else{
					ll ret = 0;
					for(int k = j; k <= u; k ++){
						ret += dp[u][k];
					}
					dp[i][j] = ret;
				}
			}
			tmp += dp[i][j];
		}
		dp[i][i] = 1;
		tmp += 1;
		ans[i] = tmp;
	}
}
int main(){
	int n;
	init();
	while(scanf("%d",&n)&&n){
		cout << ans[n] << endl;
	}
	return 0;
}