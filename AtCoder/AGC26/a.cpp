#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], n;
map<int,int> mp;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i], mp[a[i]]=1;
	int ans = 0, cnt = 1;
	for(int i = 1; i < n; i ++) {
		if(a[i] == a[i+1]) {
			while(mp[cnt] == 1) cnt++;
			a[i+1] = cnt;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}