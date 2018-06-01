#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n, k, tmp, flag;

int main(){
	scanf("%d",&n);
	scanf("%d",&k);
	flag = 1;
	for(int i = 2; i <= n; i ++){
		scanf("%d",&tmp);
		if(k >= tmp) flag++;
	} 		
	int i = 0;
	for(i = 0; i <= 20; i ++){
		if((1<<i) > flag)break;
	}
	//cout << flag<< endl;
	printf("%d\n",i-1);
	return 0;
}