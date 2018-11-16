#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N], b[N], n;

int main() {
	cin >> n;
	ll ans = n;
	for(int i = 0; i < n; i ++) cin >> a[i] >> b[i];
	sort(a,a+n);
	sort(b,b+n);
	for(int i = 0; i < n; i++) {
		ans += 1LL*max(a[i], b[i]);
	}
	cout << ans << endl;
	return 0;
}