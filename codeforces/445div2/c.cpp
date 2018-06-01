#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main() {
	int n, x, ans = 1;
	cin >> n;
	mp[0] = 1;
	for(int i = 1; i <= n; i ++) {
		cin >>x;
		if(mp[x]) {
			mp[i] = mp[x];
			mp[x] = 0;
		} else {
			ans ++;
			mp[i] = ans;
		}
	}
	cout << ans << endl;
	return 0;
}
