#include <bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 50010;
int tree[N<<2];

void pushDown(int rt) {
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
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

void update(int pos, int add, int l, int r, int rt) {
	if(l == r) {
		tree[rt] += add;
		return ;
	}
	int m = (l+r)>>1;
	if(m >= pos) update(pos, add, lson);
	else update(pos, add, rson);
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
	int t, n;
	cin >> t;
	for(int ca = 1; ca <= t; ca ++){
		printf("Case %d:\n",ca);
		cin >> n;
		build(1,n,1);
		char s[10];
		while(scanf("%s", s)) {
			int x, y;
			if(s[0] =='E') break;
			scanf("%d%d", &x, &y);
			if(s[0] == 'A'){
				update(x,y,1,n,1);
			}else if(s[0] == 'S') {
				update(x,-y,1,n,1);
			} else {
				printf("%d\n",query(x,y,1,n,1));
			}
		}
	}
	return 0;
}