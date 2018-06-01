#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
const int MAX = 100010;
char str[MAX],s[30],str1[MAX];
int nex[MAX],extend[MAX];
map<char,char> mp;
void init(){
	int len = strlen(str1),a,p;
	nex[0] = len;
	for(int i = 1, j = -1; i < len; i ++, j--){
		if(j < 0 || i+nex[i-a] >= p){
			if(j < 0)
				p=i,j=0;
			while(p < len && str1[p]==str1[j])
				p++,j++;
			nex[i] = j;
			a = i;
		}else nex[i] = nex[i-a];
	}
}
void KMP(){
	int a,p;
	int len = strlen(str), len1 = strlen(str1);
	for(int i = 1, j = -1; i < len; i++,j--){
		if(j<0 || i+nex[i-a] >= p){
			if(j < 0)
				p=i,j=0;
			while(p < len && str[p]==str1[j])
				p++,j++;
			extend[i] = j;
			a = i;
		}else extend[i] = nex[i-a];
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",s,str);
		for(int i = 0;i < 26; i ++)
			mp[s[i]] = 'a'+i;
		for(int i = 0; str[i]; i ++)
			str1[i] = mp[str[i]];
		printf("%s",str,str1);
		init();
		KMP();
		int k,len=strlen(str);
		//printf("\n------%s---------\n",str1);
		for(k = (len+1)/2; k < len; k++){
			if(k+extend[k] == len)
				break;
		}
		//printf("\n+++++++++%d++++++\n",k);
		for(int i =len-k ;i < k; i++){
			putchar(str1[i]);
		}
		printf("\n");
	}
	return 0;
}