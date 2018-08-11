#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int w[N], a[N][2];
map<string,int> mp;
int main() {
	int n, m, q;
	string s;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; i ++) scanf("%d", &w[i]);
	for(int i = 1; i <= m; i ++) {
		cin >> s;
		for(int i = 0; i < n; i ++) a[i][s[i]-'0']++;
		mp[s]++;
	}
	while(q--) {
		cin >> s;

	}
	return 0;
}