#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N], b[N];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	int n, m, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			scanf("%d%d", &a[i], &b[i]);
			if(b[i] == 1) ans++;
		}
		sort(a+1,a+1+n,cmp);
		double cnt = 0;
		for(int i = 1; i <= min(ans,m); i ++) {
			cnt += 0.5*a[i];
		}
		for(int i = min(ans,m)+1; i <= n; i ++) cnt += a[i];
		printf("%.1f\n",cnt);
	}
	return 0;
}