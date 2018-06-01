#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[400010];
int nex[400010];
int a[400010];
void init(){
	int j = nex[0] = -1, i = 0;
	int len = strlen(str);
	while(i < len){
		if(j == -1 || str[i] == str[j]) nex[++i] = ++j;
		else j = nex[j];
	}
}
int main(){
	while(scanf("%s",str)!=EOF){
		init();
		int k = 0,len = strlen(str);
		int i = len;
		while(nex[i]){
			a[k++] = nex[i];
			i = nex[i];
		}
		for(int i = k-1; i >= 0; i --){
			printf("%d ",a[i]);
		}
		printf("%d\n",len);
	}
	return 0;
}
