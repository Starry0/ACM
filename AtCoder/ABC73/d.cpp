#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
using namespace std;
const int N = 220;
int g[N][N], r[N];
int main(){
	memset(g, 0, sizeof(g));
	int n, m, R;
	cin >> n >> m >> R;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			g[i][j] = i==j?0:Inf;
		}
	}
	for(int i = 1; i <= R; i ++) {
		cin >> r[i];
	}
	for(int i = 1; i <= m; i ++) {
		int v, u, w;
		cin >> v >> u >> w;
		if(g[u][v] > w) {
			g[u][v] = g[v][u] = w;
		}
	}
	for(int k = 1; k <= n; k ++) {
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
			}
		}
	}
	sort(r+1, r+1+R);
	int ans = Inf;
	do{
		int ans1 = 0;
		for(int i =  1; i < R; i ++) {
			ans1 += g[r[i]][r[i+1]];
		}
		ans = min(ans, ans1);		
	}while(next_permutation(r+1,r+1+R));
	printf("%d\n",ans);
	return 0;
}