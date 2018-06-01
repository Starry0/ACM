#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 1e6+10;
char str[MAX];
int nex[MAX];
void init(){
	int j = nex[0] = -1, i = 0;
	int len = strlen(str);
	while(i < len){
		if(j == -1 || str[i] == str[j]){
			nex[++i] = ++j;
		}else j = nex[j];
	}
}
int main(){
	while(scanf("%s",str)!=EOF){
		if(str[0] == '.')break;
		init();
		int len = strlen(str);
		int ans = len - nex[len];
		if(len%ans==0)
			printf("%d\n",len/ans);
		else printf("1\n");
		memset(str,0,sizeof(str));
		memset(nex,0,sizeof(nex));
	}
	return 0;
}