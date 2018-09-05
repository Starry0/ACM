#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> vs[N];
map<int,int> mp[N];
int a[N], d[N];
int main() {
	int n, x, y;
	cin >> n;
	for(int i = 1; i < n; i ++) {
		cin >> x >> y;
		vs[x].push_back(y);
		vs[y].push_back(x);
		mp[x][y] = mp[y][x] = 1;
	}
	for(int i = 1; i <= n; i ++) cin >> a[i];
	d[1] = 1;
	queue<int> que;
	que.push(1);
	while(que.size()) {
		int v = que.front(); que.pop();
		for(auto u : vs[v]) {
			if(d[u] == 0) {
				d[u] = d[v] + 1;
				que.push(u);
			}
		}
	}
	// for(int i = 1; i <= n; i ++) printf("%d ",d[i]);printf("\n");
	for(int i = 1; i < n; i ++) {
		if(d[a[i]] > d[a[i+1]]) return 0*printf("No\n");
	}
	int l = 2;
	que.push(1);
	while(que.size()) {
		int v = que.front(); que.pop();
		while(l <= n) {
			if(mp[v].count(a[l])) {
				que.push(a[l]); l ++;
			} else break;
		}
	}
	if(l == n+1) printf("Yes\n");
	else printf("No\n");
	return 0;
}