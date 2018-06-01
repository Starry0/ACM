#include <iostream>
#include <stdio.h>
#include <string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX = 50010;
int lsum[MAX<<2], rsum[MAX<<2], msum[MAX<<2];
int col[MAX<<2];
void PushDown(int rt, int m){
	if(col[rt] != -1){
		col[rt<<1] = col[rt<<1|1] = col[rt];
		msum[rt<<1] = lsum[rt<<1] = rsum[rt<<1] = col[rt]?0:m-(m>>1);
		msum[rt<<1|1] = lsum[rt<<1|1] = rsum[rt<<1|1] = col[rt]?0:(m>>1);
		col[rt] = -1;
	}
}
void PushUp(int rt, int m){
	lsum[rt] = lsum[rt<<1];
	rsum[rt] = rsum[rt<<1|1];
	if(lsum[rt] == m-(m>>1)) lsum[rt] += lsum[rt<<1|1];
	if(rsum[rt] == (m>>1)) rsum[rt] += rsum[rt<<1];
	msum[rt] = max(lsum[rt<<1|1]+rsum[rt<<1],max(msum[rt<<1],msum[rt<<1|1]));
}

void build(int l, int r, int rt){
	msum[rt] = lsum[rt] = rsum[rt] = r-l+1;
	col[rt] = -1;
	if(l == r)return;
	int m = (l+r)>>1;
	build(lson);
	build(rson);
}
void update(int LL, int RR, int c, int l, int r, int rt){
	if(LL <= l && r <= RR){
		msum[rt] = lsum[rt] = rsum = c?0:r-l+1;
		col[rt] = c;
		return;
	}
	PushDown(rt,r-l+1);
	int m = (l+r)>>1;
	if(LL <= m) update(LL,RR,c,lson);
	if(m < RR) update(LL,RR,c,rson);
	PushUp(rt,r-l+1);
}
int query(int w, int l, int r, int rt){
	if(l == r)return l;
	PushDown(rt,r-l+1);
	int m = (l+r)>>1;
	if(msum[rt] >= w)return(w,lson);
	else if(rsum[rt<<1]+lsum[rt<<1|1] >= w)return m-rsum[rt<<1]+1;
	return query(w,rson);
}
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		build(1,n,1);
		while(m--){
			int op,a,b;
			scanf("%d",&op);
			if(op == 1){
				scanf("%d",&a);
				if(msum[1] < a)puts("0");
				else{
					int p = query(a,1,n,1);
					printf("%d\n",p);
					update(p,p+a-1,1,1,n,1);
				}
			}else{
				scanf("%d %d",&a,&b);
				update(a,a+b-1,0,1,n,1);
			}
		}
	}
}