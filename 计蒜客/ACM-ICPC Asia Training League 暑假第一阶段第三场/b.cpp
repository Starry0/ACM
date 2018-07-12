#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1e3+10;
vector<int> vs[N], pre[N];
bool vis[N];
bool ok(int v) {
	for(int i = 0; i < pre[v].size(); i ++) {
		if(!vis[pre[v][i]]) return false;
	}
	return true;
}

void dfs(int  v) {
	vis[v] = true;
	for(int i = 0; i < vs[v].size(); i ++) {
		if(!vis[vs[v][i]]) {
			dfs(vs[v][i]);
			break;
		}
	}
}

int main() {
	int n, k, v, u;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> k;
		for(int j = 0; j < k; j ++) {
			cin >> v;
			vs[v].push_back(i);
			pre[i].push_back(v);
		}
	}
	int ans = 0;
	while(1) {
		for(int i = 0; i < n; i ++) {
			if(ok(i) && !vis[i]) {
				dfs(i);
				ans++;
				for(int i = 0; i < n; i ++) {
					printf("%d vis:%d\n",i,vis[i] );
				}printf("\n");
			}
			
		}
		int cnt = 0;
		for(int i = 0; i < n; i ++) {
			if(vis[i]) cnt++;
		}
		if(cnt == n) break;
	}

	cout << ans << endl;
	return 0;
}