#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
int a[N*2], c[N*2];
int x, n;
int main() {
	cin >> n;
	int ans = INF;
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		c[x] ++;
		int tmp = x, step = 1;
		while(true) {
			int y = tmp, cnt = step;
			while(y*2 < N*2) {
				a[y*2] += cnt; c[y*2]++;
				y *= 2; cnt++;
			}
			while(tmp%2 == 0) {
				a[tmp/2] += step; c[tmp/2] ++;
				tmp /= 2; step++;
			}
			if(tmp == 1) break;
			tmp /= 2;
			c[tmp]++;
			a[tmp] += step;
			step ++;
		}
	}
	for(int i = 1; i < 2*N; i ++) {
		if(c[i] == n) ans = min(ans, a[i]);
	}
	printf("%d\n",ans);
	return 0;
}