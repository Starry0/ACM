#include <bits/stdc++.h>
#define ll long long
#define lson l,m,rt<<|1
#define rson m+1,r,rt<<1|1
const int N = 5e4+10;
using namespace std;
int n, q, cnt = 1;
int a[N], vis[N],h[N];
vector<int> vs[N];
map<int,int> mp;
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(!mp.count(a[i])) mp[a[i]] = cnt++;
		vs[mp[a[i]]].push_back(i);
	}
	sort(a+1,a+1+n);
	int m = 2;
	for(int i = 2; i <= n; i ++) {
		if(a[i]!=a[i-1]) a[m++] = a[i];
	}
	for(int i = 1; i < m; i ++) printf("%d ",a[i]);printf("\n");
	int ans = 1;
	h[0] = vis[0] = vis[n+1] = 1;
	for(int i = 1; i < m; i ++) {
		for(int j = 0; j < vs[mp[a[i]]].size(); j ++) {
			int id = vs[mp[a[i]]][j];
			if(vis[id-1]&&vis[id+1]) ans--;
			if(!vis[id-1]&&!vis[id+1]) ans++;
			vis[id] = 1;
		}
		h[i] = ans;
	}
	// for(int i = 1; i < m; i ++) printf("%d %d\n",i,h[i]);
	while(q--) {
		int x;
		scanf("%d", &x);
		int ans = lower_bound(a+1,a+m,x)-a;
		if(a[ans] != x) ans--;
		printf("%d\n",h[ans]);
	}
	return 0;
}