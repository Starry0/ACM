#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 10010;
int a[N], b[N];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= m; i ++) {
		if(i > n) break;
		b[i] = a[i];
	}
	if(n < m) {
		for(int i = 1; i <= n; i ++) ans = max(ans, b[i]);
	} else {
		int pos = m+1;
		while(pos <= n) {
			int MIN = b[1], id = 1;
			for(int i = 2; i <= m; i ++) {
				if(b[i] < MIN) {
					MIN = b[i];
					id = i;
				}
			}
			b[id] += a[pos++];
		}
		for(int i = 1; i <= m; i ++) ans = max(ans, b[i]);
	}
	printf("%d\n",ans);
	return 0;
}