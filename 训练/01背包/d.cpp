#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int MAX = 50000+5;
int dp[MAX];

int main(){
	int n, ww,w,p,c;
	scanf("%d %d",&n,&ww);
	for(int i = 0; i < n; i ++){
		scanf("%d %d %d",&w,&p,&c);
		for(int k = 1, flag =1;; k*=2){
			if(k*2 >= c){
				k = c-k+1;
				flag = 0;
			}
			//cout << k << ' ' ;
			for(int j = ww; j >= k*w; j --){
				dp[j] = max(dp[j],dp[j-k*w]+k*p);
			}
			if(flag == 0)break;
		}
		//cout << endl;
	}
	printf("%d\n",dp[ww]);
	return 0;
}