#include <iostream>
#include <stdio.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX = 5010;
int tree[MAX<<2];
void Push(int rt){
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void build(int l, int r, int rt){
	tree[rt] = 0;
	if(l == r) return;
	int m = (l+r)>>1;
	build(lson);
	build(rson);
}
void update(int x, int l, int r, int rt){
	if(l == r){
		tree[rt]++;
		return;
	}
	int m = (l+r)>>1;
	if(x <= m)update(x,lson);
	else update(x,rson);
	Push(rt);
}
int query(int LL, int RR, int l, int r, int rt){
	if(LL <= l && r <= RR){
		return tree[rt];
	}
	int m = (l+r)>>1;
	int sum = 0;
	if(m >= LL)sum+=query(LL,RR,lson);
	if(m < RR)sum+=query(LL,RR,rson);
	return sum;
}
int x[MAX];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		build(0,n-1,1);
		int sum = 0;
		for(int i = 0; i < n; i ++){
			scanf("%d",&x[i]);
			sum += query(x[i],n-1,0,n-1,1);
			update(x[i],0,n-1,1);
		}
		int res = sum;
		for(int i = 0; i < n; i ++){
			sum +=n-2*x[i]-1;
			res = min(res,sum);
		}
		printf("%d\n",res);
	}
	return 0;
}