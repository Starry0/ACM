#include <iostream>
#include <stdio.h>
#include <string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX = 50010;
int tree[MAX<<2];
void Push(int rt){
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void build(int l, int r, int rt){
	if(l == r){
		scanf("%d",&tree[rt]);
		return ;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	Push(rt);
}
void update(int x, int p, int l, int r, int rt){
	if(l == r){
		tree[rt] += p;
		return;
	}
	int m = (l+r)>>1;
	if(m >=x)update(x,p,lson);
	else update(x,p,rson);
	Push(rt);
}
int query(int LL, int RR, int l, int r, int rt){
	if(LL <= l && r <= RR){
		return tree[rt];
	}
	int m = (l+r)>>1;
	int sum = 0;
	if(m >= LL) sum+=query(LL,RR,lson);
	if(m < RR) sum+=query(LL,RR,rson);
	return sum;
}
int main(){
	int t,n,k=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("Case %d:\n",k++);
		build(1,n,1);
		char str[10];
		int l,r;
		while(scanf("%s",str)!=EOF){
			if(str[0] == 'E')break;
			scanf("%d %d",&l,&r);
			if(str[0] == 'Q'){
				printf("%d\n",query(l,r,1,n,1));
			}else if(str[0] == 'A'){
				update(l,r,1,n,1);
			}else {
				update(l,-r,1,n,1);
			}
		}
	}
	return 0;
}