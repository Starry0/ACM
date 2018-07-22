#include <bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 1e5+10;
int tree[N<<2], lazy[N<<2];

void PushUp(int rt) {
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}

void PushDown(int rt, int m) {
	if(lazy[rt]) {
		lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
		tree[rt<<1] = (m-(m>>1))*lazy[rt];
		tree[rt<<1|1] = (m>>1)*lazy[rt];
		lazy[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	lazy[rt] = 0;
	tree[rt] = 1;
	if(l == r) return ;
	int m = (l+r)>>1;
	build(lson);
	build(rson);
}

void update(int L, int R, int c, int l, int r, int rt) {
	if(L <= l && r <= R) {
		lazy[rt] = c;
		tree[rt] = c*(r-l+1);
		return ;
	}
	PushDown(rt, r-l+1);
	int m = (l+r)>>1;
	if(L <= m) update(L, R, c, lson);
	if(m < R) update(L, R, c, rson);
	PushUp(rt);
}

int main() {
	int t, n, m;
	cin >> t;
	for(int ca = 1; ca <= t; ca ++) {
		cin >> n >> m;
		build(1, n, 1);
		while(m--) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			update(a, b, c, 1, n, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n",ca,tree[1]);
	}
	return 0;
}