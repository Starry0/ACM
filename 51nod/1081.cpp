#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
#define lowbit(x) x&(-x)
const int MAX = 5e4+10;
ll a[MAX];
void add(int x, ll y){
	while(x < MAX){
		a[x] += y;
		x += lowbit(x);
	}
}
ll query(int x){
	ll sum = 0;
	while(x > 0){
		sum += a[x];
		x -= lowbit(x);
	}
	return sum;
}
int main(){
	int n,q;
	ll num;
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++)scanf("%lld",&num),add(i,num);
	scanf("%d",&q);
	while(q--){
		int i,l;
		scanf("%d %d",&i,&l);
		printf("%lld\n",query(i+l-1)-query(i-1));
	}
	return 0;
}