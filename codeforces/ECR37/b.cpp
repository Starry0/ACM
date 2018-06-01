#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int t, n;
int l[N], r[N];
int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i ++) cin >> l[i] >> r[i];
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			ans = max(ans,l[i]);
			printf("%d ",ans>r[i]?0:ans++);
		}
		printf("\n");
	}
	return 0;
}