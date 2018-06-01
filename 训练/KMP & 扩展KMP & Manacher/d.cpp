#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[100010];
int nex[100010];
void init(){
	int j = nex[0] = -1, i = 0;
	int len = strlen(str);
	while(i < len){
		if(j == -1 || str[i] == str[j]){
			nex[++i] = ++j;
		}else j = nex[j];
	}
}
int KMP(){
	int len = strlen(str);
	int ans = len -nex[len];
	if(!nex[len])return len;
	else if(len%ans) return ans-len%ans;
	else return 0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		init();
		printf("%d\n",KMP());
	}
	return 0;
}