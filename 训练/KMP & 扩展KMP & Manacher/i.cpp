#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str1[50010],str2[50010];
int nex[50010],extend[50010];

void init(){
	int len = strlen(str1);
	nex[0] = len;
	int a, p;
	for(int i = 1,j=-1; i < len; i++,j--){
		if(j < 0 || i+nex[i-a] >= p){
			if(j < 0)
				p = i,j = 0;
			while(p < len && str1[p] == str1[j])
				p++,j++;
			nex[i] = j;
			a = i;
		}else nex[i] = nex[i-a];
	}
}
void getExtend(){
	int a,p;
	int len1 = strlen(str1), len2 = strlen(str2);
	for(int i = 0,j=-1; i < len2; i++,j--){
		if(j < 0 || i+nex[i-a]>=p){
			if(j<0)
				p=i,j=0;
			while(p<len2 && j<len1 && str2[p] == str1[j])
				p++,j++;
			extend[i] = j;
			a = i;
		}else extend[i] = nex[i-a];
	}
}
int main(){
	while(scanf("%s%s",str1,str2)!=EOF){
		init();
		getExtend();
		int i, len2 = strlen(str2);
		for(i = 0; i < len2; i ++){
			if(i+extend[i] == len2){
				printf("%s %d\n",str2+i,extend[i]);
				break;
			}
		}
		if(i == len2)printf("0\n");
	}
	return 0;
}