#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N], n, x, c[N], t;
int main() {
	cin >> t;
	int b = 0, m, xx, y;
	for(int i = 0; i < t; i ++) {
		scanf("%d", &x);
		a[x]++;
		b = max(b, x);
	}
	xx = 1;
	for(int i = 1; a[i] ; i ++) {
		if(a[i] != 4*i) {
			xx = i;
			break;
		}
	}
	for(int n = 1; n <= t; n ++) {
		if(t%n == 0) {
			memset(c, 0, sizeof(c));
			m = t/n;
			y = n+m-b-xx;
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= m; j ++) {
					c[abs(i-xx)+abs(j-y)]++;
				}
			}
			bool flag = 1;
			for(int i = 0; i <= b; i ++) {
				if(a[i] != c[i]) {
					flag = 0;
					break;
				}
			}
			if(flag) {
				return 0*printf("%d %d\n%d %d\n",n,m,xx,y);
			}
		}
	}
	printf("-1\n");
	return 0;
}