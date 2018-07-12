#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
map<string,int> mp;
map<int,string> mp1;
vector<int> vs[N];
vector<string> vs1[N];
bool vis[N];
void dfs(int x) {
	vis[x] = 1;
	for(int i = 0; i < vs[x].size(); i ++) {
		if(!vis[vs[x][i]]) {
			dfs(vs[x][i]);
		}
	}
}

int main() {
	int n, k;
	cin >> n;
	string s;
	for(int i = 1; i <= n; i ++) {
		cin >> s;
		mp[s] = i;
		mp1[i] = s;
		cin >> k;
		for(int j = 0; j < k; j ++) {
			cin >> s;
			vs1[i].push_back(s);
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j < vs1[i].size(); j ++) {
			vs[mp[vs1[i][j]]].push_back(i);
		}
	}
	for(int i = 1; i <= n; i ++) {
		if(mp1[i].find("PROGRAM") != string::npos && !vis[i]) {
			for(int j = 0; j < vs[i].size(); j ++) {
				dfs(vs[i][j]);
				vis[vs[i][j]] = 1;
			}
			vis[i] = 1;
		}
	}
	int ans = 0;
	for(int i =1; i <= n; i ++) {
		if(!vis[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}