#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int a[N], b[33];
map<int,int> mp;
int main() {
	int n, x;
	for(int i = 0; i < 31; i ++) b[i] = (1<<i);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		mp[a[i]]++;
	}
	int ans = 0;
	map<int,int>::iterator it = mp.begin();
	for(; it != mp.end(); it ++) {
		bool flag = false;
		for(int j = 30; j > 0; j --) {
			int tmp = b[j] - (*it).first;
			if(tmp <= 0) break;
			if(mp.count(tmp)) {
				if(tmp == (*it).first && mp[tmp] == 1) continue;
				// cout << (*it).first << ' '<< tmp << endl;
				flag = true;
				break;
			}
		}
		if(!flag) {
			ans += (*it).second;
		}
	}
	cout << ans << endl;
	return 0;
}