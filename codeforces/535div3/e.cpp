#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 330;
int n, m, a[N], sum[N];
struct Nod {
	int l, r;
}e[N];
int vis[N], vis1[N];

int main() {
	cin >> n >> m;
	int MAX = 0;
	for(int i = 1; i <= n; i ++) cin >> a[i], MAX = max(MAX,a[i]);
	for(int i = 1; i <= n; i ++) a[i] = -(a[i]-MAX);
	for(int i = 1; i <= m; i ++) cin >> e[i].l >> e[i].r;
	MAX = 0;
	for(int i = 1; i <= n; i ++) {
		memset(vis, 0, sizeof(vis));
		memset(sum, 0, sizeof(sum));
		int cnt = 0, MIN = INF;
		for(int j = 1; j <= m; j ++) {
			if(e[j].l <= i && i <= e[j].r) {
				vis[j] = 1;
				cnt ++;
				sum[e[j].l] ++; sum[e[j].r+1] --;
			}
		}
		for(int j = 1; j <= n; j ++) {
			sum[j] += sum[j-1];
			MIN = min(MIN,sum[j]+a[j]);
		}
		if(cnt+a[i] - MIN > MAX) {
			MAX = cnt+a[i] - MIN;
			for(int j = 1; j <= n; j ++) vis1[j] = vis[j];
		}
	}
	printf("%d\n",MAX);
	int ret = 0;
	for(int i = 1; i <= n; i ++) {
		if(vis1[i]) ret++;
	}
	printf("%d\n",ret);
	for(int i = 1; i <= n; i ++) {
		if(vis1[i]) printf("%d ",i);
	}printf("\n");
	return 0;
}