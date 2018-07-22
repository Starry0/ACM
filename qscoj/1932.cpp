#include <iostream>
#include <stdio.h>
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 1e6+10;
int tree[N<<2], n, c;

void PushUp(int rt) {
	tree[rt] = min(tree[rt<<1], tree[rt<<1|1]);
}

void build(int l, int r, int rt) {
	if(l == r) {
		if(l == 1) tree[rt] = 0;
		else tree[rt] = -1;
		return;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	PushUp(rt);
}

void update(int pos, int val, int l, int r, int rt) {
	if(l == r) {
		tree[rt] = val;
		return;
	}
	int m = (l+r)>>1;
	if(m >= pos) update(pos, val, lson);
	else update(pos, val, rson);
	PushUp(rt);
}
int query(int val, int l, int r, int rt) {
	if(l == r) {
		return l;
	}
	int m = (l+r)>>1;
	if(tree[rt<<1] < val) return query(val, lson);
	else return query(val, rson);
}
int main() {
	cin >> n;
	build(1,n,1);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &c);
		int ans = query(i-c,1,n,1);
		printf("%d",ans);		
		if(i != n) printf(" ");
		update(ans, i, 1, n, 1);
	}
	return 0;
}