#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main() {
	int n, A, b, c, t;
	cin >> n >> A >> b >> c >> t;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(b >= c) {
		printf("%d\n",n*A);
	} else {
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			ans += (t-a[i])*(c-b)+A;
		}
		printf("%d\n",ans);
	}
	return 0;
}