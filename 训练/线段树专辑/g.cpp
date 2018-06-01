#include <iostream>
#include <stdio.h>
#include <string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAX = 1e5+10;
int tree[MAX<<2], col[MAX<<2];
void PushUp(int rt){
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void PushDown(int rt, int m){
	if(col[rt]){
		col[rt<<1] = col[rt<<1|1] = col[rt];
		tree[rt<<1] = (m-(m>>1))*col[rt];
		tree[rt<<1|1] = (m>>1) * col[rt];
		col[rt] = 0;
	}
}
void build(int l, int r, int rt){
	col[rt] = 0;
	tree[rt] = 1;
	if(l == r) return;
	int m = (l+r) >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int L, int R, int c, int l, int r, int rt){
	if(L <= l && r <= R){
		col[rt] = c;
		tree[rt] = c*(r-l+1);
		return;
	}
	PushDown(rt,r-l+1);
	int m = (l+r)>>1;
	if(L <= m) update(L,R,c,lson);
	if(R > m) update(L,R,c,rson);
	PushUp(rt);
}
int main(){
	int t,n,m;
	scanf("%d",&t);
	for(int i = 1; i <= t; i ++){
		scanf("%d %d",&n,&m);
		build(1,n,1);
		while(m--){
			int l,r,num;
			scanf("%d %d %d",&l,&r,&num);
			update(l,r,num,1,n,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",i,tree[1]);
	}
	return 0;
}
