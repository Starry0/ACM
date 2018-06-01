#include <iostream>
#include <stdio.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX = 200010;
int tree[MAX<<2];
void PushUp(int rt){
	tree[rt] = max(tree[rt<<1],tree[rt<<1|1]);
}
void build(int l, int r, int rt){
	if(l == r){
		scanf("%d",&tree[rt]);
		return;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int x, int p, int l, int r, int rt){
	if(l == r){
		tree[rt] = p;
		return;
	}
	int m = (l+r)>>1;
	if(m >= x)update(x,p,lson);
	else update(x,p,rson);
	PushUp(rt);
}
int query(int LL, int RR, int l, int r, int rt){
	if(LL <= l && r <= RR){
		return tree[rt];
	}
	int m = (l+r)>>1;
	int cnt = 0;
	if(m >= LL) cnt = max(cnt,query(LL,RR,lson));
	if(m < RR) cnt = max(cnt,query(LL,RR,rson));
	return cnt;
}
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		build(1,n,1);
		while(m--){
			char str[10];
			int l, r;
			scanf("%s%d%d",str,&l,&r);
			if(str[0] == 'Q'){
				printf("%d\n",query(l,r,1,n,1));
			}else{
				update(l,r,1,n,1);
			}
		}
	}
	return 0;
}