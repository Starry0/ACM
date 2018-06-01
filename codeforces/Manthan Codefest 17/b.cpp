#include <bits/stdc++.h>
#define ll long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
const int N = 1e5+10;
ll tree[N<<2];
ll a[N];
ll max(ll x, ll y) {
	return x > y ? x: y;
}
void Push(int rt) {
	tree[rt] = max(tree[rt<<1], tree[rt<<1|1]);
}
void build(int l, int r, int rt) {
	if(l == r) {
		scanf("%lld", &tree[rt]);
		a[l] = tree[rt];
		return ;
	}
	int m = (l + r) >> 1;
	if(m >= l) build(lson);
	if(m < r) build(rson);
	Push(rt); 
}
ll query(int l, int r, int rt, int L, int R) {
	if(L <= l && r <= R) {
		return tree[rt];
	}
	int m = (l + r) >> 1;
	int MAX = 0;
	if(m >= L) MAX = max(MAX, query(lson, L, R));
	if(m < R) MAX = max(MAX, query(rson, L, R));
	return MAX;
}
int main() {
	int n;
	ll q, p, r;
	cin >> n >> p >> q >> r;
	build(1, n, 1);
	if(n == 0) return 0*printf("%lld\n",(p+r+q)*tree[1]);
	int l = 1, rr = n;
	ll MAX = 1LL*-10000000000000000;
	while(l <= r) {
		ll x = query(1, n, 1, l, rr);
		MAX = max(MAX, p*a[l]+q*a[x]+r*a[rr]);
		ll y = (a[rr-1]-a[rr])*r, y1 = (a[l+1]-a[l])*p;
		if(y > y1) r--;
		else l++;
	}
	printf("%d\n",MAX);
	return 0;
}