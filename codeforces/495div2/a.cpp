#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], n, x, d;
int main() {
	cin >> n >> d;
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a,a+n);
	int ans = 2;
	for(int i = 0; i < n-1; i ++) {
		if(a[i+1]-a[i]-2*d > 0) ans += 2;
		else if(a[i+1]-a[i]-2*d == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}