#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1e6+10;
int a[N], n, q, dmin[N][30];
void init(){
	for(int i = 1; i <= n; i ++) dmin[i][0] = a[i];
	for(int j = 1; (1<<j) <= n; j ++){
		for(int i = 1; i+(1<<j)-1 <= n; i ++){
			dmin[i][j] = min(dmin[i][j-1],dmin[(1<<(j-1))+i][j-1]);
		}
	}
}
int query(int l, int r){
	int k = 0;
	while(1<<(k+1) <= (r-l+1))k++;
	return min(dmin[l][k],dmin[r-(1<<k)+1][k]);
}
int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++) scanf("%d",&a[i]);
	init();
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}