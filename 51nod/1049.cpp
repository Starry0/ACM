#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
int n, a[50010];
int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i ++) scanf("%d",a+i);
	ll Max = 0, maxn = 0;
	for(int i = 0; i < n; i ++){
		maxn = max(0LL,maxn) + a[i];
		Max = max(Max,maxn);
	}
	printf("%lld\n",Max);
	return 0;
}