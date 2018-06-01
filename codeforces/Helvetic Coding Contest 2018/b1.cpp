#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<int> vs[N];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		vs[u].push_back(v);
		vs[v].push_back(u);
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		if(vs[i].size() == 1)ans++;
	}
	cout <<ans<< endl;
	return 0;
}