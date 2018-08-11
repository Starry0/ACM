#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
int a[N];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		ans += a[i];
		printf("%d ",ans/m);
		ans %= m;
	}
	return 0;
}
