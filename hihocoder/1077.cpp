#include <iostream>
#include <stdio.h>
#include <string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX = 1e6+10;
int tree[MAX<<2];
void PushUp(int rt){
	tree[rt] = min(tree[rt<<1],tree[rt<<1|1]);
}
void build(int l, int r, int rt){
	if(l == r){
		scanf("%d",&tree[rt]);
		return ;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int x,int p, int l, int r, int rt){
	if(l == r){
		tree[rt] = p;
		return;
	}
	int m = (l+r)>>1;
	if(m >= x) update(x,p,lson);
	else update(x,p,rson);
	PushUp(rt);
}
int query(int LL,int RR, int l, int r, int rt){
	if(LL <= l && r <= RR){
		return tree[rt];
	}
	int m = (l+r)>>1;
	int res = 1e7;
	if(m >= LL) res = min(res,query(LL,RR,lson));
	if(m < RR) res = min(res,query(LL,RR,rson));
	return res;
}
int main(){
	int n,q;
	scanf("%d",&n);
	build(1,n,1);
	scanf("%d",&q);
	while(q--){
		int num,l,r;
		scanf("%d",&num);
		if(num){
			scanf("%d %d",&l,&r);
			update(l,r,1,n,1);
		}else {
			scanf("%d %d",&l,&r);
			printf("%d\n",query(l,r,1,n,1));
		}
	}
	return 0;
}