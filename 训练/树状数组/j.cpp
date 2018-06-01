#include <iostream>
#include <stdio.h>
#include <string.h>
#define lowbit(x) (x&(-x))
using namespace std;

int main(){
	int n,x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		printf("%d %d\n",x-lowbit(x)+1,x+lowbit(x)-1);
	}
	return 0;
}