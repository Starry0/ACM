#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 1e6+10;
int n, nex[MAX];
char str[MAX];
void init(){
	int j = nex[0] = -1, i = 0;
	int len = strlen(str);
	while(i < len){
		if(j == -1 || str[i] == str[j]){
			nex[++i] = ++j;
		}else j = nex[j];
	}
}
void KMP(){
	int len = strlen(str);
	for(int i = 2; i <= len; i ++){
		int flag = 0, ans = i-nex[i];
		if(i%ans || ans == i)continue;
		printf("%d %d\n",i,i/(i-nex[i]));
	}
	printf("\n");
}
int main(){
	int k = 1;
	while(scanf("%d",&n)!=EOF){
		if(!n)break;
		scanf("%s",str);
		printf("Test case #%d\n",k++);
		init();
		/*for(int i = 0; i <= strlen(str); i ++){
			printf("%d ",nex[i]);
		}
		printf("\n");*/
		KMP();
	}
	return 0;
}