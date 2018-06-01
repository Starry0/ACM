#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[110][110],str1[110],str2[110];
int nex[110];

void init(int len){
	int j = nex[0] = -1, i = 0;
	while(i < len){
		if(j == -1 || str1[i] == str1[j]) nex[++i] = ++j;
		else j = nex[j];
	}
}
bool KMP(char *s){
	int len = strlen(s),len1 = strlen(str1);
	int i = 0, j = 0;
	while(i < len){
		if(j == -1 || str1[j] == s[i]){
			i++;j++;
			if(j == len1)return true;
		}else j = nex[j];
	}
	return false;
}
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0; i < n; i ++)scanf("%s",str[i]);
		int flag = true,flag1 =false;
		for(int len = 60; len >= 3; len--){
			for(int i = 0; i <= 60-len; i ++){
				strncpy(str1,str[0]+i,len);
				init(len);
				flag = true;
				for(int j = 1; j < n; j ++){
					if(!KMP(str[j])){
						flag = false;
						break;
					}
				}
				if(flag){
					flag1 = true;
					if(strlen(str1) > strlen(str2))strcpy(str2,str1);
					else if(strlen(str1) == strlen(str2) && strcpy(str1,str2)>0){
						strcpy(str2,str1);
					}
				}
				memset(str1,0,sizeof(str1));
				memset(nex,0,sizeof(nex));
			}
		}
		if(flag1)printf("%s\n",str2);
		else printf("no significant commonalities\n");
	}
	return 0;
}