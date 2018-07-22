#include <bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 200010;
int tree[N<<2];

void pushDown(int rt) {
	tree[rt] = max(tree[rt<<1], tree[rt<<1|1]);
}

void build(int l, int r, int rt) {
	if(l == r) {
		scanf("%d", &tree[rt]);
		return ;
	}
	int m = (l+r)>>1;
	if(m >= l) build(lson);
	if(m < r) build(rson);
	pushDown(rt);
}

void update(int pos, int val, int l, int r, int rt) {
	if(l == r) {
		tree[rt] = val;
		return ;
	}
	int m = (l+r)>>1;
	if(m >= pos) update(pos, val, lson);
	else update(pos, val, rson);
	pushDown(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return tree[rt];
	}
	int m = (l+r)>>1;
	int ans = 0;
	if(m >= L) ans = max(ans,query(L, R, lson));
	if(m < R) ans = max(ans, query(L, R, rson));
	return ans;
}
int main() {
	int m, n, x, y;
	while(scanf("%d %d", &n, &m) != EOF){
		build(1,n,1);
		char s[10];
		while(m--) {
			scanf("%s %d %d", s, &x, &y);
			if(s[0] == 'Q') printf("%d\n",query(x, y, 1, n, 1));
			else update(x, y, 1, n, 1);
		}
	}
	return 0;
}