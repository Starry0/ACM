#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
const int N = 100010;
int a[N];
int n, m;
bool ok(int x) {
	int sum = 0, ans = 0;
	for(int i = 0; i < n; i ++) {
		sum += a[i];
		if(sum > x) {
			ans++;
			sum = a[i];
		}
	}
	if(sum != 0) ans++;
	return ans <= m;
}
int main() {
	cin >> n >> m;
	int l = 0, r = 0;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		r += a[i];
		l = max(l, a[i]);
	}
	int ans = 0;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(ok(mid)) {
			ans = mid;
			r = mid-1;
		} else l = mid+1;
	}
	printf("%d\n",ans);
	return 0;
}