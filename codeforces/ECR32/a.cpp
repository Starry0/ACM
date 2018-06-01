#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0;
	for(int i = 2; i < n; i ++) {
		if(a[i] > a[i-1] && a[i] > a[i+1]) ans++;
		if(a[i] < a[i-1] && a[i] < a[i+1]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}