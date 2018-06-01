#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main() {
	int n, x;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		mp[x] ++;
	}
	int MAX = 0;
	map<int, int> :: iterator it = mp.begin();
	for(; it != mp.end(); ++ it) {
		if(MAX < (*it).second) {
			MAX = (*it).second;
		}
	}
	cout << MAX << endl;
	return 0;
}