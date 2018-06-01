#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main() {
	int n, x;
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> x, mp[x] = i;
	map<int, int> :: iterator it = mp.begin();
	int INF = 1e9, ans;
	for(; it != mp.end(); it++) {
		if((*it).second < INF) {
			INF = (*it).second;
			ans = (*it).first;
		}
	}
	cout << ans << endl;
	return 0;
}