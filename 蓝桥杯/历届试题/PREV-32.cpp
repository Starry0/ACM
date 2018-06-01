#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], n;
int ok() {
	int ans = 0, i;
	for(i = 1; i < n; i ++) {
		if(a[i] != a[0]) break;
		else continue;
	}
	if(i == n) return -1;
	for(int i = 0; i < n; i ++) {
		if(a[i]&1) {
			a[i]++;
			ans++;
		}
	}
	return ans;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	int ans = 0, tmp;
	while((tmp=ok()) != -1) {
		ans+=tmp;
		int x = a[0];
		for(int i = 1; i < n; i ++) {
			a[i-1] += a[i]/2;
			a[i] /= 2;
		}
		a[n-1] += x/2;
		a[0] -= x/2;
	}
	cout << ans << endl;
	return 0;
}