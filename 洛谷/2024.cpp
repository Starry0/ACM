#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 50005;
int n, k, fa[N*3], ans;
void init() {
	for(int i = 0; i < N*3; i ++) fa[i] = i;
	ans = 0;
}
int find(int x) {
	if(fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
void unite(int x, int y) {
	x = find(x), y = find(y);
	if(x < y) fa[x] = y;
	else fa[y] = x;
}
bool same(int x, int y) {
	return find(x) == find(y);
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	init();
	for(int i = 1; i <= k; i ++) {
		int flag, x, y;
		scanf("%d %d %d", &flag, &x, &y);
		if(0 >= x || n < x || 0 >= y || y > n || (flag == 2 && x == y)) {
			ans ++;
			continue;
		}
		if(flag == 1) {
			if(same(x,y+n) || same(x, y+2*n)) {
				ans++;
				continue;
			} else {
				unite(x, y);
				unite(x+n, y+n);
				unite(x+2*n, y+2*n);
			}
		} else {
			if(same(x,y) || same(x,y+2*n)) {
				ans ++;
				continue;
			} else {
				unite(x,y+n);
				unite(x+n,y+2*n);
				unite(x+2*n,y);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}