#include <iostream>
#include <stdio.h>
#include <string.h>
#define lowbit(x) x&(-x)
using namespace std;
const int MAX = 32010;
int c[MAX],a[MAX];

void add(int x, int y){
	while(x < MAX){
		c[x] += y;
		x += lowbit(x);
	}
}
int query(int x){
	int sum = 0;
	while(x > 0){
		sum += c[x];
		x -= lowbit(x);
	}
	return sum;
}
int main(){
	int n,x,y;
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++){
		scanf("%d %d",&x,&y);
		add(++x,1);
		a[query(x)-1]++;
	}
	for(int i = 0; i < n; i ++){
		printf("%d\n",a[i]);
	}
	return 0;
}