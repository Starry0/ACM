#include <bits/stdc++.h>
using namespace std;
int a[3001];
int main() {
	int n, x, y;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> x >> y;
		a[i] = x+y+a[i-1]-8;
	}
	int ans = 0;
	for(int i =1 ; i <= n; i ++) ans += a[i];
	cout << ans << endl;
	return 0;
}