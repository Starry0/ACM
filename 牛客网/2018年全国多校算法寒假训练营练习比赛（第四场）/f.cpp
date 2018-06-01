#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> vs[55];
bool vis[55], flag;
int n, m;
void init() {
	for(int i = 0; i < 55; i ++) {
		vs[i].clear();
		vis[i] = 0;
	}
	flag = false;
}
void dfs(int x) {
	for(int i = 0; i < vs[x].size(); i ++) {
		int y = vs[x][i];
		if(y == n) {
			flag = true;
			return;
		}
		if(!vis[y]) {
			vis[y] = true;
			dfs(y);
		}
	}
}
int main() {
	while(cin >> n >> m) {
		init();
		for(int i = 1; i <= m; i ++) {
			int x, y;
			cin >> x >> y;
			vs[x].push_back(y);
		}
		dfs(1);
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}