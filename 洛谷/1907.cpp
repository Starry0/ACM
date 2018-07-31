#include <bits/stdc++.h>
using namespace std;
int a[55];
int main() {
	int t, n, m;
	cin >> t;
	while(t--) {
		cin >> n;
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		sort(a+1,a+1+n);
		if(a[n] == 1) {
			if(n&1) printf("Brother\n");
			else printf("John\n");
			continue;
		}
		for(int i = 1; i <= n; i ++) ans ^= a[i];
		if(ans) printf("John\n");
		else printf("Brother\n");
	}
	return 0;
}