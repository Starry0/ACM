#include <iostream>
#include <stdio.h>
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 100010;
ll tree[N<<2], lazy[N<<2];

void PushUp(int rt) {
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}

void PushDown(int rt, int m) {
	if(lazy[rt]) {
		lazy[rt<<1] += lazy[rt];
		lazy[rt<<1|1] += lazy[rt];
		tree[rt<<1] += lazy[rt]*(m-(m>>1));
		tree[rt<<1|1] += lazy[rt]*(m>>1);
		lazy[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	if(l == r) {
		scanf("%lld", &tree[rt]);
		return;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	PushUp(rt);
}

void update(int L, int R, int val, int l, int r, int rt) {
	if(L <= l && r <= R) {
		lazy[rt] += val;
		tree[rt] += (ll)val*(r-l+1);
		return;
	}
	PushDown(rt, r-l+1);
	int m = (l+r)>>1;
	if(m >= L) update(L, R, val, lson);
	if(m < R) update(L, R, val, rson);
	PushUp(rt);
}

ll query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return tree[rt];
	}
	PushDown(rt, r-l+1);
	int m = (l+r)>>1;
	ll ans = 0;
	if(m >= L) ans += query(L, R, lson);
	if(m < R) ans += query(L, R, rson);
	return ans;
}

int main() {
	int n, q, l, r, v;
	scanf("%d %d", &n, &q);
	build(1,n,1);
	while(q--) {
		char s[10];
		scanf("%s", s);
		if(s[0] == 'Q') {
			scanf("%d%d", &l, &r);
			printf("%lld\n",query(l, r, 1, n, 1));
		} else {
			scanf("%d%d%d", &l, &r, &v);
			update(l,r,v,1,n,1);
		}
	}
	return 0;
}