#include <bits/stdc++.h>
using namespace std;
const int N = 3e4+10;
int a[N];
int main() {
	int n, w, ans = 0;
	cin >> w >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a,a+n);
	int l = 0, r = n-1;
	while(l < r) {
		if(a[l]+a[r] <= w) l++,r--;
		else r--;
		ans++;
	}
	if(l == r) ans++;
	cout << ans << endl;
	return 0;
}