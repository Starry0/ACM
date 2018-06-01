#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 500010;
int t,v[27],p[MAX*2],sum[MAX],per[MAX],pos[MAX];
char str[MAX*2];

void init(){
	int id = 0,len = strlen(str);
	for(int i = len; i >= 0; i--){
		str[i+i+2] = str[i];
		str[i+i+1] = '#';
	}
	str[0] = '*';
	for(int i = 2; i <2*len+1; i++){
		if(id+p[id] > i) p[i] = min(p[2*id-i],p[id]+id-i);
		else p[i] = 1;
		while(str[i-p[i]] == str[i+p[i]])
			++p[i];
		if(id+p[id] < p[i]+i) id = i;
		if(i-p[i] == 0)per[p[i]-1] = t+1;
		if(i+p[i] == len*2+2)pos[p[i]-1] = t+1;
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		for(int i = 0; i < 26; i ++) scanf("%d",&v[i]);
		scanf("%s",str);
		int len = strlen(str);
		for(int i = 0; i < len; i ++){
			sum[i+1] = sum[i]+v[str[i]-'a'];
		}
		init();
		int ans = -1;
		for(int i = 1; i < len; i ++){
			int tmp = 0;
			if(per[i] == t+1)tmp+=sum[i];
			if(pos[len-i] == t+1) tmp+=(sum[len]-sum[i]);
			if(tmp > ans) ans=tmp;
		}
		printf("%d\n",ans);
		memset(per,0,sizeof(per));
		memset(pos,0,sizeof(pos));
	}
	return 0;
}