#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
int main() {
	int n, m, l, r;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> l >> r;
		for(int j = l; j <= r; j ++) a[j] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= m; i ++) if(!a[i]) ans++;
	printf("%d\n",ans);
	for(int i = 1; i <= m; i ++) if(!a[i]) printf("%d ",i);
	return 0;
}