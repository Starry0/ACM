#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[1010],str1[1010];
int nex[1010];
void init(){
	int j = nex[0] = -1, i = 0;
	int len1 = strlen(str1);
	while(i < len1){
		if(j == -1 || str1[i] == str1[j]){
			nex[++i] = ++j;
		}else j = nex[j];
	}
}
int KMP(){
	int i = 0,j = 0, ans = 0;
	int len = strlen(str), len1 = strlen(str1);
	while(i < len){
		if(j == -1 || str[i] == str1[j]){
			i++;j++;
			if(j == len1){
				ans++;j=0;
			}
		}else j = nex[j];
	}
	return ans;
}

int main(){
	while(scanf("%s",str)!=EOF){
		if(!strcmp(str,"#"))break;
		scanf("%s",str1);
		init();
		printf("%d\n",KMP());
		memset(str,0,sizeof(str));
		memset(str1,0,sizeof(str1));
	}
	return 0;
}