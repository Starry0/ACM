#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int fa[N];
int find(int x) {
	return fa[x] = (fa[x] == x ? fa[x]: find(fa[x]));
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) fa[i] = i;
	while(m--) {
		int x, y, z;
		scanf("%d%d%d", &z, &x, &y);
		if(z == 1) {
			fa[find(x)] = find(y);
		} else {
			if(find(x) == find(y)) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}