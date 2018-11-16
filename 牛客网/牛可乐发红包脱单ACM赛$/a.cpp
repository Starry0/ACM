#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
map<int, int> mp1[N], mp2[N];
map<int, int>::iterator it; 
int main() {
	int n, v, u;
	cin >> n;
	for(int i = 1; i < n; i ++) {
		cin >> v >> u;
		mp1[v][u] = 1;
		mp1[u][v] = 1;
	}
	for(int i = 1; i < n; i ++) {
		cin >> v >> u;
		mp2[v][u] = 1;
		mp2[u][v] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		for(it = mp1[i].begin(); it != mp1[i].end(); ++ it) {
			if(!mp2[i].count((*it).first)) ans++;
		}
	}
	cout << ans/2 << endl;
	return 0;
}