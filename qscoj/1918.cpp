#include <iostream>
#include <stdio.h>
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 1e6+10;
ll sum[N<<2], MIN[N<<2], MAX[N<<2];
int n, m;

void PushUp(int rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
	MIN[rt] = min(MIN[rt<<1], MIN[rt<<1|1]);
	MAX[rt] = max(MAX[rt<<1], MAX[rt<<1|1]);
}

void update(int pos, int val, int l, int r, int rt) {
	if(l == r) {
		sum[rt] = MIN[rt] = MAX[rt] = val;
		return;
	}
	int m = (l+r)>>1;
	if(m >= pos) update(pos, val, lson);
	else update(pos, val, rson);
	PushUp(rt);
}

ll query_sum(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return sum[rt];
	}
	int m = (l+r)>>1;
	ll SUM = 0;
	if(m >= L) SUM += query_sum(L, R, lson);
	if(m < R) SUM += query_sum(L, R, rson);
	return SUM;
}
ll query_max(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return MAX[rt];
	}
	int m = (l+r)>>1;
	ll ans = -1e10;
	if(m >= L) ans = max(ans, query_max(L, R, lson));
	if(m < R) ans = max(ans, query_max(L, R, rson));
	return ans;
}
ll query_min(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return MIN[rt];
	}
	int m = (l+r)>>1;
	ll ans = 1e10;
	if(m >= L) ans = min(ans, query_min(L, R, lson));
	if(m < R) ans = min(ans, query_min(L, R, rson));
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	while(m--) {
		int op, a, b;
		scanf("%d%d%d", &op, &a, &b);
		if(op == 0) {
			update(a, b, 1, n, 1);
		} else {
			printf("%lld\n",query_sum(a,b,1,n,1)-query_max(a,b,1,n,1)-query_min(a,b,1,n,1));
		}
	}
	return 0;
}