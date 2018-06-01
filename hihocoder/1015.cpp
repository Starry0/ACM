#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[10100],str1[1000100];
int nex[10100];
void init(){
	nex[0] = -1;
	int len = strlen(str), i = 0, j = -1;
	while(i < len){
		if(j == -1 || str[i] == str[j]){
			nex[++i] = ++j;
		}else{
			j = nex[j];
		}
	}
}
int KMP(){
	int i = 0, j = 0;
	int sum = 0;
	int len = strlen(str), len1 = strlen(str1);
	while(i < len1){
		if(j == -1 || str1[i] == str[j]){
			if(j == len-1){
				sum++;
				j = nex[j];
			}else{
				++i;++j;
			}
		}else j = nex[j];
	}
	return sum;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		scanf("%s%s",str,str1);
		//cin>>str>>str1;
		init();
		printf("%d\n",KMP());
		memset(nex,0,sizeof(nex));
	}
	return 0;
}