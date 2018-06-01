#include <iostream>
#include <stdio.h>
#include <string.h>
#define rson m+1,r,rt<<1|1
#define lson l,m,rt<<1
#define ll long long
const int MAX = 1e5+10;
ll tree[MAX<<2], col[MAX<<2];
void PushUp(int rt){
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void PushDown(int rt, int m){
	if(col[rt]){
		col[rt<<1] = col[rt<<1|1] = col[rt];
		tree[rt<<1] = col[rt]*(m-(m>>1));
		tree[rt<<1|1] = col[rt]*(m>>1);
		col[rt] = 0;
	}
}
void build(int l, int r, int rt){
	if(l == r){
		scanf("%lld",&tree[rt]);
		return;
	}
	PushDown(rt,r-l+1);
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int LL, int RR, int num, int l, int r, int rt){
	if(LL <= l && r <= RR){
		col[rt] = num;
		tree[rt] = (r-l+1)*num;
		return;
	}
	PushDown(rt,r-l+1);
	int m = (l+r)>>1;
	if(LL <= m)update(LL,RR,num,lson);
	if(m < RR) update(LL,RR,num,rson);
	PushUp(rt);
}
ll query(int LL, int RR, int l, int r, int rt){
	if(LL <= l && r <= RR){
		return tree[rt];
	}
	PushDown(rt,r-l+1);
	int m = (l+r)>>1;
	ll res = 0;
	if(LL <= m) res += query(LL,RR,lson);
	if(m < RR) res += query(LL,RR,rson);
	return res;
}
int main(){
	int n,q;
	scanf("%d",&n);
	build(1,n,1);
	scanf("%d",&q);
	while(q--){
		int l, r, num;
		scanf("%d",&num);
		if(num){
			scanf("%d %d %d",&l,&r,&num);
			update(l,r,num,1,n,1);
		}else {
			scanf("%d %d",&l,&r);
			printf("%lld\n",query(l,r,1,n,1));
		}
	}
	return 0;
}