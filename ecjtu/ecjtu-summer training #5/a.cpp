#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

int main(){
	int n,k=1;
	while(scanf("%d",&n)!=EOF){
		if(n < 0)break;
		int ans = 1, i;
		for(i = 0; ans < n; i ++){
			ans = ans*2;
		}
		printf("Case %d: %d\n",k++,i);
	}
	return 0;
}