#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N], n;
map<int,int> mp;
bool vis[N];
int main() {
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		if(!mp.count(a[i])) {
			cnt ++;
		}
		mp[a[i]] ++;
	}
	ll ans = 0;
	for(int i = 0; i < n; i ++) {
		mp[a[i]]--;
		if(mp[a[i]] == 0) cnt--;
		if(!vis[a[i]]) {
			ans += 1LL*cnt;
			vis[a[i]] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}
