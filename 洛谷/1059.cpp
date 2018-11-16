#include <bits/stdc++.h>
using namespace std;
int a[1010], n;
int main() {
	int ans = 0, x;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		if(!a[x]) ans++;
		a[x] = 1;
	}
	cout << ans << endl;
	for(int i = 1; i <= 1000; i ++) if(a[i]) cout << i << ' ';
	return 0;
}