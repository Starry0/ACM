#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
map<int,int> mp;
int main() {
	int n, x, MAX = 0;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		mp[x] ++;
		MAX = max(MAX, mp[x]);
	}
	cout << MAX << endl;
	return 0;
}