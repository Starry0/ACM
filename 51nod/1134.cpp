#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int Inf = 1<<30;
const int MAX = 50010;
int a[MAX], dp[MAX];
int main(){
	int n;
	for(int i = 0; i < MAX; i ++)dp[i] = Inf;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)scanf("%d",&a[i]);
	for(int i = 0; i < n; i ++){
		*lower_bound(dp,dp+n,a[i]) = a[i];
	}
	printf("%d\n",lower_bound(dp,dp+n,Inf)-dp);
	return 0;
}
/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int Inf = 1<<30;
const int MAX = 50010;
int a[MAX], dp[MAX];
int main(){
	int n;
	for(int i = 0; i < MAX; i ++)dp[i] = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)scanf("%d",&a[i]);
	int res = 0;
	for(int i = 0; i < n; i ++){
		dp[i] = 1;
		for(int j = 0; j < i; j ++){
			if(a[j] < a[i]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		res = max(dp[i],res);
	}
	printf("%d\n",res);
	return 0;
}*/