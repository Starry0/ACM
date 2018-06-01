#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

int main(){
	int n,k,m;
	while(scanf("%d %d %d",&n,&k,&m)!=EOF){
		if(n==0)break;
		int f = 0;
		for(int i = 2; i <= n; i ++){
			f = (f+k)%i;
		}
		int ans = (m-k+f+1)%n;
		if(ans <= 0)ans+=n;
		printf("%d\n",ans);
	}
	return 0;
}