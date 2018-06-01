#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 100010;
char str[MAX<<1];
int p[MAX<<1];
int solve(){
	int len = strlen(str), id = 0;
	for(int i = len; i >= 0; i --){
		str[i+i+2] = str[i];
		str[i+i+1] = '#';
	}
	str[0] = '*';
	int ans = 0;
	for(int i =2; i < len*2+1; i ++){
		if(id+p[id] > i) p[i] = min(p[2*id-i],p[id]+id-i);
		else p[i] = 1;
		while(str[i+p[i]] == str[i-p[i]])++p[i];
		if(id+p[id] < i+p[i])id = i;
		if(ans < p[i])ans = p[i];
	}
	return ans-1;
}
int main(){
	cin>>str;
	printf("%d\n",solve());
	return 0;
}