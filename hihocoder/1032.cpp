/*#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[1000010];

int solve(){
	int len = strlen(str), ans = 0;
	for(int i = 0; i < len; i ++){
		for(int j = 0; i-j>=0 && i+j < len; j++){
			if(str[i-j] != str[i+j])break;
			if(j*2+1 > ans) ans=j*2+1;
		}
		for(int j = 0; i-j >= 0 && i+j+1 < len; j ++){
			if(str[i-j] != str[i+j+1])break;
			if(2*j+2 > ans) ans = 2*j+2;
		}
	}
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		printf("%d\n",solve());
		memset(str,0,sizeof(str));
	}
	return 0;
}*/


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 1e6+10;
char str[MAX<<1];
int p[MAX<<1];
int solve(){
	int ans = 0, id = 0, len = strlen(str);
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
		if(ans < p[i]) ans = p[i];
	}
	return ans-1;
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		printf("%d\n",solve());
		memset(str,0,sizeof(str));
		memset(p,0,sizeof(p));
	}
	return 0;
}