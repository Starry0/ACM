#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int fa[N];
int find(int x) {
	return fa[x] = (fa[x] == x ? fa[x]: find(fa[x]));
}
int main() {
	int n, m, q, x, y;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i ++) fa[i] = i;
	while(m--) {
		cin >> x >> y;
		fa[find(x)] = find(y);
	}
	while(q--) {
		cin >> x >> y;
		printf(find(x)==find(y)?"Yes\n":"No\n");
	}
	return 0;
}