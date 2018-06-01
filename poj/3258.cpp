#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 50010;
int a[N];
int L, n, m;
bool ok(int x) {
	int ans = 0, pre = 0;
	for(int i = 1; i <= n; i ++) {
		if(a[i] - a[pre] >= x && L - a[i] >= x) {
			ans++;
			pre = i;
		}
	}
	return ans >= n-m;
}
int main() {
	cin >> L >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	int l = 0, r = L, ans;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(ok(mid)) {
			ans = mid;
			
			l = mid+1;
		} else r = mid-1;
	}
	printf("%d\n",ans);
	return 0;
}