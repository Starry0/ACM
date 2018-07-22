#include <bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 5010;
int tree[N<<2], a[N];

void pushDown(int rt) {
	tree[rt] = (tree[rt<<1] + tree[rt<<1|1]);
}

void update(int pos, int val, int l, int r, int rt) {
	if(l == r) {
		tree[rt] += val;
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
	if(m >= L) ans += query(L, R, lson);
	if(m < R) ans += query(L, R, rson);
	return ans;
}
int main() {
	int m, n, x, y;
	while(scanf("%d", &n) != EOF){
		memset(tree, 0, sizeof(tree));
		int ans = 0;
		for(int i = 0; i < n; i ++) {
			scanf("%d", &a[i]);
			ans += 	query(a[i], n-1, 0, n-1, 1);
			update(a[i], 1, 0, n-1, 1);
		}
		int cnt = ans;
		for(int i = 0; i < n; i ++) {
			cnt = cnt - a[i] + n - a[i] - 1;
			ans = min(ans, cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}