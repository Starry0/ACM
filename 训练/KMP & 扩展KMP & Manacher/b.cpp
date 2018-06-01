#include <iostream>
#include <string.h>
#include <stdio.h>
char str[10010],str1[1000010];
int nex[10010];
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
	int i  = 0, j = 0, sum = 0;
	int len = strlen(str), len1 = strlen(str1);
	while(j < len1){
		if(i == -1 || str[i] == str1[j]){
			i++;j++;
		}else i = nex[i];
		if(i == len) sum++;
	}
	return sum;
}
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s%s",str,str1);
		init();
		/*for(int i = 0; i <= strlen(str); i ++){
			printf("%d ",nex[i]);
		}
		printf("\n");*/
		printf("%d\n",KMP());
		memset(str,0,sizeof(str));
		memset(str1,0,sizeof(str1));
		memset(nex,0,sizeof(nex));
	}
	return 0;
}