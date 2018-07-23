/*#include <iostream>
#include <stdio.h>
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 1e6+10;
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
	int n, q;
	scanf("%d%d",&n,&q);
	build(1,n,1);
	while(q--) {
		int o, l, r, p;
		scanf("%d%d%d%d", &o, &l, &r, &p);
		if(o == 1) update(l,r,-p,1,n,1);
		else update(l,r,p,1,n,1);
	}
	int l,r;
	cin >> l >> r;
	printf("%lld\n",query(l,r,1,n,1));
	return 0;
}*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
ll a[N], b[N];
int main() {
	int n, m, o, l, r, p;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	while(m--) {
		scanf("%d%d%d%d", &o, &l, &r, &p);
		if(o == 1) b[l] -= p, b[r+1] += p;
		else b[l] += p, b[r+1] -= p;
	}
	scanf("%d%d", &l, &r);
	ll ans = 0;
	for(int i = 1; i <= r; i ++) {
		b[i] += b[i-1];
		if(i >= l) {
			ans += a[i];
			ans += b[i];
		}
	}
	printf("%lld\n",ans);
	return 0;
}