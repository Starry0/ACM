#include <bits/stdc++.h>
using namespace std;
int a[10010];

int main() {
	int L, m, l, r;
	cin >> L >> m;
	for(int i = 1; i <= m; i ++) {
		cin >> l >> r;
		for(int j = l; j <= r; j ++) {
			a[j] = 1;
		}
	}
	int ans = 0;
	for(int i = 0; i <= L; i ++) if(!a[i]) ans++;
	cout << ans << endl;
	return 0;
}