#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int a[N][N], b[N][N], c[N][N];
int main() {
	int t, n, m, p, q;
	cin >> t;
	for(int ca = 1; ca <= t; ca ++) {
		cin >> n >> m >> p >> q;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) cin >> a[i][j];
		}
		for(int i = 1; i <= p; i ++) {
			for(int j = 1; j <= q; j ++) cin >> b[i][j];
		}
		memset(c, 0, sizeof(c));
		printf("Case %d:\n",ca);
		if(m != p) printf("ERROR\n");
		else {
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= q; j ++) {
					for(int k = 1; k <= m; k ++) {
						c[i][j] += a[i][k]*b[k][j];
					}
				}
			}
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= q; j ++) {
					printf("%d%c",c[i][j], " \n"[j==q]);
				}
			}
		}
	}
	return 0;
}