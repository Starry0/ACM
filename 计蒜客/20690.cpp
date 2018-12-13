#include <bits/stdc++.h>
#define lowbit(x) (-x&(x))
using namespace std;
const int N = 1e5+10;
vector<int> vs[N];
typedef pair<int,int> P;
vector<P> vs1[N];
int a[N], d[N], sum[N], dp[N][2], res;

int dfs(int v, int f) {
	a[++res] = v;
	int sum = 0;
	for(auto u : vs[v]) {
		if(u == f) continue;
		d[u] = dfs(u, v);
		sum += d[u]+1;
	}
	return sum;
}
void add(int x, int y) {
	while(x < N) {
		sum[x] += y;
		x += lowbit(x);
	}
}
int query(int x) {
	int s = 0;
	while(x > 0) {
		s += sum[x];
		x -= lowbit(x);
	}
	return s;
}
int main() {
	int n, p, u, v;
	scanf("%d%d", &n, &p);
	for(int i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		vs[u].push_back(v);
		vs[v].push_back(u);
	}
	d[p] = dfs(p, -1);
	// for(int i = 1; i <= n; i ++) printf("%d ",a[i]);printf("\n");
	// for(int i = 1; i <= n; i ++) printf("%d ",d[a[i]]);printf("\n");
	for(int i = 1; i <= n; i ++) {
		vs1[i+d[a[i]]].push_back(P(a[i],i));
	}
	for(int i = n; i >= 1; i --) {
		for(auto p : vs1[i]) {
			dp[p.first][0] = query(p.first);
		}
		dp[a[i]][1] = query(a[i]);
		// printf("%d\n",i);
		add(a[i], 1);
	}
	for(int i = 1; i <= n; i ++) printf("%d%c",dp[i][1]-dp[i][0]," \n"[i==n]);
	return 0;
}