#include <iostream>
#include <stdio.h>
#include <string.h>
const int MAX = 1e6+10;
char str[MAX];
int nex[MAX],a[MAX/3];
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
	int j = nex[len],i = 0;
	while(j != -1){
		if(j<=MAX/3)
			a[i++] = j;
		j = nex[j];
	}
	if(i == 0 || a[0] == 0) return 0;
	for(int k = 0; k < i; k ++){
		for(int l = a[k]+1; l <= len-a[k]; ++l){
			if(nex[l] == a[k])
				return a[k];
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		init();
		printf("%d\n",KMP());
		memset(str,0,sizeof(str));
	}
	return 0;
}