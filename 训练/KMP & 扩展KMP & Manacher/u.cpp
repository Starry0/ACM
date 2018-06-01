#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 100010;
int a[MAX*2],p[MAX*2],n;

int solve(){
	int ans = 0,id = 0;
	for(int i = n; i >= 0; i --){
		a[i+i+2] = a[i];
		a[i+i+1] = -1;
	}
	a[0] = -2;
	for(int i = 2; i < 2*n+1; i ++){
		if(p[id]+id>i)p[i] = min(p[2*id-i],p[id]+id-i);
		else p[i] = 1;
		while(a[i-p[i]] == a[i+p[i]] && a[i-p[i]] <= a[i-p[i]+2])
			++p[i];
		if(p[id]+id < p[i]+i)id = i;
		if(ans < p[i]) ans = p[i];
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
		printf("%d\n",solve()-1);
	}
	return 0;
}