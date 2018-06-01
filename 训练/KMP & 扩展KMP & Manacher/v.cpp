#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 200010;
char c,str[MAX<<1],gg;
int p[MAX<<1];

void solve(){
	int ans = 0, cnt = 0,id = 0, len = strlen(str);
	for(int i = len; i >= 0; i --){
		str[i+i+2] = str[i];
		str[i+i+1] = '#';
	}
	str[0] = '*';
	for(int i = 2; i<2*len+1; i ++){
		if(p[id] + id > i) p[i] = min(p[2*id-i],p[id]+id-i);
		else p[i] = 1;
		while(str[i-p[i]] == str[i+p[i]])++p[i];
		if(p[id] + id < p[i]+i) id = i;
		if(ans < p[i]) ans = p[i],cnt=i;
	}
	//printf("%d\n",p[cnt]);
	if(ans < 3){
		printf("No solution!\n");
		return;
	}
	if(str[cnt] == '#'){
		 printf("%d %d\n",(cnt-p[cnt])/2,(cnt+p[cnt]-4)/2);
		 for(int i = (cnt-p[cnt]+2); i <= (cnt+p[cnt]-2); i+=2){
			 printf("%c",str[i]);
		 }
		 printf("\n");
	}else{
		printf("%d %d\n",(cnt-p[cnt])/2,(cnt+p[cnt]-4)/2);
		for(int i = (cnt-p[cnt]+2); i <= (cnt+p[cnt]-2); i+=2){
			printf("%c",str[i]);
		}
		printf("\n");
	}
}

int main(){
	while(scanf("%c %s%c",&c,str,&gg)!=EOF){
		for(int i = 0; str[i]; i ++){
			str[i] = str[i]-c+'a';
			if(str[i] < 'a') str[i] +=26;
		}
		//cout << str << endl;
		solve();
		memset(str,0,sizeof(str));
	}
	return 0;
}