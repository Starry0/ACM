/*#include <bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 1e4;
int tree[N<<2], num[N], n, last;

void push(int rt) {
	if(tree[rt] != -1) tree[rt<<1] = tree[rt<<1|1] = tree[rt];
	tree[rt] = -1;
}

void update(int L, int R, int c, int l, int r, int rt) {
	if(L <= l && r <= R) {
		tree[rt] = c;
		return ;
	}
	push(rt);
	int m = (l+r)>>1;
	if(L <= m) update(L, R, c, lson);
	if(m < R) update(L, R, c, rson);
}

void query(int l, int r, int rt) {
	if(l == r) {
		if(tree[rt] != -1 && tree[rt] != last) num[tree[rt]]++;
		last = tree[rt];
		return ;
	}
	push(rt);
	int m = (l+r)>>1;
	query(lson);
	query(rson);
}
int main() {
	while(cin >> n) {
		memset(tree, -1, sizeof(tree));
		memset(num, 0, sizeof(num));
		int a, b, c;
		for(int i = 1; i <= n; i ++) {
			cin >> a >> b >> c;
			if(a < b) update(a+1,b,c,1,N,1);
		}
		last = -1;
		query(1,8000,1);
		for(int i = 0; i <= 8000; i ++) {
			if(num[i]) printf("%d %d\n",i,num[i]);
		}
	}
	return 0;
}*/


#include <bits/stdc++.h>
using namespace std;
const int N = 8010;
int color[N], num[N], n;
int main() {
	while(cin >> n) {
		int a, b, c;
		memset(color, -1, sizeof(color));
		memset(num, 0, sizeof(num));
		int MIN = N, MAX = -1;
		for(int i = 0; i < n; i ++) {
			cin >> a >> b >> c;
			MAX = max(MAX, b);
			MIN = min(MIN, a);
			for(int j = a; j < b; j ++) {
				color[j] = c;
			}
		}
		// for(int i = 0; i < 10; i ++) printf("%d %d\n",i,color[i] );
		if(color[MIN] != -1) num[color[MIN]]++;
		for(int i = MIN+1; i <= MAX; i ++) {
			if(color[i] != color[i-1] && color[i] != -1) {
				num[color[i]]++;
			}
		}
		for(int i = 0; i < N; i ++) {
			if(num[i]) printf("%d %d\n",i,num[i]);
		}
		printf("\n");
	}
	return 0;
}