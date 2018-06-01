#include <iostream>
#include <stdio.h>
#include <string.h>
const int MAX = 1000010;
char str[MAX];
int nex[MAX],a[MAX];
void init(){
	int len = strlen(str),a,p;
	nex[0] = len;
	for(int i = 1,j = -1; i < len; i ++,j--){
		if(j<0 || i+nex[i-a] >= p){
			if(j < 0)
				p=i,j=0;
			while(p<len && str[p]==str[j])
				p++,j++;
			nex[i]=j;
			a=i;
		}else nex[i] = nex[i-a];
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 1; i <= n; i ++){
			scanf("%s",str);
			init();
			int k = 0,len = strlen(str);
			for(int j = 1; j < len; j++){
				if(j+nex[j] == len)
					a[k++] = j;
			}
			printf("Case #%d: %d\n",i,k+1);
			for(int j = 0; j < k; j ++)
				printf("%d ",a[j]);
			printf("%d\n",len);
		}
	}
	return 0;
}