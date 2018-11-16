#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
bool vis[N];
int main() {
	int n, m, x;
	cin >> n >> m;
	string s1, s2;
	for(int i = 1; i <= m; i ++) {
		cin >> x >> s1;
		if(i == 1 || s1 != s2) vis[x] = 1;
		s2 = s1;
	}
	int ans = 0, cnt = 0;
	for(int i = 1; i <= n; i ++) if(!vis[i]) ans++;
	for(int i = 1; i <= n; i ++) {
		if(vis[i] == 0) {
			printf("%d",i);
			cnt++;
			if(cnt == ans) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}