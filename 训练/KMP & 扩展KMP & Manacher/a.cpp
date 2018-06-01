#include <iostream>
#include <stdio.h>
using namespace std;
int a[1000000],b[10010],nex[10010];
int n,m;
void init(){
	int j = nex[0] = -1, i = 0;
	while(i < m){
		if(j == -1 || b[i] == b[j]){
			nex[++i] = ++j;
		}else j = nex[j];
	}
}
int KMP(){
	int i = 0, j = 0, ans = -1;
	while(i < n){
		if(j == -1 || a[i] == b[j]){
			++i;++j;
			if(j == m){
				ans = i-m+1;
				break;
			}
		}else j = nex[j];
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n; i ++)scanf("%d",&a[i]);
		for(int i = 0; i < m; i ++)scanf("%d",&b[i]);
		init();
		printf("%d\n",KMP());
	}
	return 0;
}