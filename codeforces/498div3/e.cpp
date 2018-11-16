#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
std::vector<int> v[N];
int n, q, x, ans = 1, tot;
int a[N], cnt[N];
map<int,int> mp;
void dfs(int u) {
	int tmp = ans;
	for(int i = 0; i < v[u].size(); i ++) {
		ans++;
		a[tot++] = v[u][i];
		dfs(v[u][i]);
	}
//	printf("%d %d %d\n",u,ans,tmp );
	cnt[u] = ans - tmp+1;
}
int main() {
	cin >> n >> q;
	for(int i = 2; i <= n; i ++) {
		scanf("%d", &x);
		v[x].push_back(i);
	}
	a[tot++] = 1;
	cnt[1] = n;
	dfs(1);
	for(int i = 0; i < tot; i ++) {
		mp[a[i]] = i;
	}
	// for(int i = 1; i <= tot; i ++) printf("%d ", cnt[i]);printf("\n");
	while(q--) {
		int u, x;
		scanf("%d%d",&u, &x);
		if(cnt[u] < x) printf("-1\n");
		else {
			printf("%d\n",a[mp[u]+x-1]);
		}
	}
	return 0;
}