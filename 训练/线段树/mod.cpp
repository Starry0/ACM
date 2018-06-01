#include <iostream>
#include <stdio.h>
#include <string.h>
#define rson m+1,r,rt<<1|1
#define lson l,m,rt<<1
using namespace std;
const int MAX = 1e6+10;
int tree[MAX];
void Push(int rt){
	tree[rt] = min(tree[rt<<1],tree[rt<<1|1]);
}
void build(int l, int r, int rt){
	if(l==r){
		scanf("%d",&tree[rt]);
		return ;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	Push(rt);
}
int query(int l, int r, int rt, int LL, int RR){
	if(LL <= l && r <= RR){
		return tree[rt];
	}
	int m = (l+r) >> 1;
	int Min = 1e7;
	if(m >= LL) Min = min(Min,query(lson,LL,RR));
	if(m < R) Min = min(Min,query(rson,LL,RR));
	return Min;
}
void update(int l, int r, int rt, int x, int p){
	if(l == r){
		tree[rt] = p;
		return;
	}
	int m = (l+r)>>1;
	if(m >= p)update(lson,x,p);
	else update(rson,x,p);
	Push(rt);
}
int main(){
	
	return 0;
}