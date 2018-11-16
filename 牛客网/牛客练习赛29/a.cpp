#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
ll a[N], n;
int main() {
	cin >> n;
	for(int i = 1; i <= n; cin >> a[i++]);	
	ll ans = 0;	
	for(int i = 1; i <= n; i ++) {
		if(a[i] > 0) ans += a[i];
		else ans += i*a[i];
	}
	cout << ans << endl;
	return 0;
}