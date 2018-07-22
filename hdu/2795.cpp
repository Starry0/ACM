#include <bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 2e5+10;
int tree[N<<2];
int n, h, w, x;

void pushDown(int rt) {
	tree[rt] = max(tree[rt<<1], tree[rt<<1|1]);
}

void build(int l, int r, int rt) {
	tree[rt] = w;
	if(l == r) return;
	int m = (l+r)>>1;
	build(lson);
	build(rson);
}

int query(int val, int l, int r, int rt) {
	if(l == r) {
		tree[rt] -= val;
		return l;
	}
	int m = (l+r)>>1;
	int ans = (tree[rt<<1] >= val) ? query(val,lson): query(val,rson);
	pushDown(rt);
	return ans;
}
int main() {
	while(scanf("%d%d%d",&h, &w, &n) != EOF){
		memset(tree, 0, sizeof(tree));
		if(h > n) h = n;
		build(1,h,1);
		while(n--) {
			scanf("%d", &x);
			if(tree[1] < x) printf("-1\n");
			else printf("%d\n",query(x, 1, h, 1));
		}
	}
	return 0;
}