#include <iostream>
#include <stdio.h>
#include <string.h>
#define lson l,m,rt<<1
#define rson m,r,rt<<1|1
using namespace std;
const int N = 2e5+10;
int tree[N<<2], ans[N];
int n, h, w, x;
struct Nod{
	int val, pos;
}e[N];

void build(int l, int r, int rt) {
	tree[rt] = r - l;
	if(tree[rt] == 1) return;
	
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int pos, int val, int l, int r, int rt) {
	tree[rt]--;
	if(r-l==1) {
		ans[l] = val;
		return ;
	}
	int m = (l+r)>>1;
	if(tree[rt<<1] > pos) update(pos, val, lson);
	else update(pos-tree[rt<<1], val, rson);
}
int main() {
	while(scanf("%d",&n) != EOF){
		memset(ans, 0, sizeof(ans));
		build(0, n, 1);
		for(int i = 0; i < n; i ++) scanf("%d%d", &e[i].pos, &e[i].val);
		for(int i = n-1; i >= 0; i --) {
			update(e[i].pos,e[i].val,0,n,1);
		}
		for(int i = 0; i < n; i ++) printf("%d%c",ans[i]," \n"[i==n-1]);
	}
	return 0;
}