#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 220;
int a[N][N], b[N];
int main() {
	int t, n, q;
	scanf("%d", &t);
	for(int ca = 1; ca <= t; ca ++) {
		// cin >> n >> q;
		scanf("%d%d", &n, &q);
		for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				scanf("%d", &a[i][j]);
			}
		}
		printf("Case #%d:\n",ca);
		while(q--) {
			
		}
	}
	return 0;
}