#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e5+10;
vector<int> vs[N];
bool vis[N];
int cnt, n, d, k;
void dfs(int x, int ans) {
	if(ans == 0) return;
	while(vs[x].size() < k && cnt <= n) {
		vs[x].push_back(cnt);
		vs[cnt].push_back(x);
		cnt++;
		dfs(cnt-1,ans-1);
	}
}
int main() {
	cin >> n >> d >> k;
	if(d >= n) return 0*printf("NO\n");
	for(int i = 1; i <= d; i ++) {
		vs[i].push_back(i+1);
		vs[i+1].push_back(i);
	}
	cnt = d+2;
	for(int i = 2; i <= d; i ++) {
		dfs(i,min(i-1,d+1-i));
	}
//	cout << cnt << endl;
	if(cnt > n) {
		printf("YES\n");
		for(int i = 1; i <= n; i ++) {
			for(int j = 0; j < vs[i].size(); j ++) {
				if(!vis[i] || !vis[vs[i][j]]) {
					printf("%d %d\n",i,vs[i][j]);
					vis[i] = vis[vs[i][j]] = 1;
				}
			}
		}
	} else printf("NO\n");
	return 0;
}