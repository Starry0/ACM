#include <iostream>
#include <stdio.h>
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 1e5+10;
int tree[N<<2], lazy[N<<2], a[N];
struct Nod{
	int op, l, r;
}e[N];

void PushUp(int rt) {
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void PushDown(int rt, int m) {
	if(lazy[rt] != -1) {
		lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
		tree[rt<<1] = (m-(m>>1))*lazy[rt];
		tree[rt<<1|1] = (m>>1)*lazy[rt];
		lazy[rt] = -1;
	}
}

void build(int l, int r, int rt, int val) {
	lazy[rt] = -1;
	if(l == r) {
		tree[rt] = (a[l] > val);
		return;
	}
	int m = (l+r)>>1;
	build(lson,val);
	build(rson,val);
	PushUp(rt);
}

void update(int L, int R, int val, int l, int r, int rt) {
	if(L <= l && r <= R) {
		lazy[rt] = val;
		tree[rt] = val*(r-l+1);
		return;
	}
	PushDown(rt, r-l+1);
	int m = (l+r)>>1;
	if(m >= L) update(L, R, val, lson);
	if(m < R) update(L, R, val, rson);
	PushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return tree[rt];
	}
	PushDown(rt, r-l+1);
	int m = (l+r)>>1;
	int ans = 0;
	if(m >= L) ans += query(L, R, lson);
	if(m < R) ans += query(L, R, rson);
	return ans;
}

int main() {
	int n, k, m;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	cin >> m;
	for(int i = 0; i < m; i ++) scanf("%d%d%d", &e[i].op, &e[i].l, &e[i].r);
	int L = 1, R = n;
	while(L < R) {
		int mid = (L+R)>>1;
		build(1,n,1,mid);
		for(int i = 0; i < m; i ++) {
			int l = e[i].l, r = e[i].r;
			int c = query(l, r, 1, n, 1);
			update(l, r, 0, 1, n, 1);
			if(e[i].op) {
				if(l <= l+c-1) update(l, l+c-1, 1, 1, n, 1);
			} else {
				if(r-c+1 <= r) update(r-c+1, r, 1, 1, n, 1);
			}
		}
		if(query(k,k,1,n,1)) L = mid+1;
		else R = mid;
	}
	printf("%d\n",L);
	return 0;
}