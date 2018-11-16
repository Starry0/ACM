#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 220;
vector<int> vs[N];
map<string,int> mp;
int flag;
void dfs(int x, int y, int f) {
	if(x == y && f == 0) flag = 1;
	if(x == y && f == 1) flag = 2;
	for(auto v : vs[x]) {
		dfs(v, y, f);
	}
}
int main() {
	int n, m, res = 1;
	cin >> n >> m;
	string s[5];
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < 5; j ++) cin >> s[j];
		if(!mp.count(s[0])) mp[s[0]] = res++;
		if(!mp.count(s[4])) mp[s[4]] = res++;
		vs[mp[s[0]]].push_back(mp[s[4]]);
	}
	while(m--) {
		flag = 0;
		for(int i = 0; i < 5; i ++) cin >> s[i];
		dfs(mp[s[0]],mp[s[4]],0);
		dfs(mp[s[4]],mp[s[0]],1);
		if(flag==0||mp[s[0]]==mp[s[4]]) printf("Pants on Fire\n");
		else if(flag == 1) printf("Fact\n");
		else if(flag == 2) printf("Alternative Fact\n");
	}
	return 0;
}