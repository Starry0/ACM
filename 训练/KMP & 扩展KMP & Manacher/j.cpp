#include <iostream>
#include <stdio.h>
#include <string.h>
const int MAX = 200010,Mod = 10007;
char str[MAX];
int nex[MAX],sum[MAX],ans;
void init(){
	int j = nex[0] = -1, i = 0;
	int len = strlen(str);
	while(i < len){
		if(j == -1 || str[i] == str[j]){
			if(j!=-1){
				sum[i] = sum[j]+1;
				ans+=sum[i];
			}
			nex[++i] = ++j;
		}
		else j = nex[j];
	}
}
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,str);
		ans = 0;
		init();
		printf("%d\n",(ans+n)%Mod);
		memset(str,0,sizeof(str));
		memset(sum,0,sizeof(sum));
	}
	return 0;
}