#include <bits/stdc++.h>
using namespace std;
int a[11], n;
int main() {
	for(int i = 0; i < 10; cin >> a[i++]);
	cin >> n;
	int ans = 0;
	for(int i = 0; i < 10; i ++) {
		if(a[i]-30 <= n) ans++;
	}
	cout << ans << endl;
	return 0;
}