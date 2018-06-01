#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX_N = 2e5+10;
int a[MAX_N], c[MAX_N], n, k, q;
int main(){
	int l, r;
	scanf("%d%d%d",&n,&k,&q);
	for(int i = 0; i < n; i ++){
		scanf("%d%d",&l,&r);
		a[l]++;
		a[r+1]--;
	}
	for(int i = 0; i < MAX_N; i ++){
		a[i] += a[i-1];
		c[i] += c[i-1] + (a[i] >= k);
	}
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",c[r]-c[l-1]);
	}
	return 0;
}