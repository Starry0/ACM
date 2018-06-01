/*
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int c, n, m;
const int N = 110;
int g[N][N], mincost[N];
bool vis[N];
void init() {
	for(int i = 0; i < N; i ++) {
		for(int j = 0; j < N; j ++) {
			if(i == j) g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
}
int prim(){
    for(int i = 1; i <= n; i ++){
        mincost[i] = g[1][i];
        vis[i] = false;
    }
    mincost[1] = 0;
    int res = 0;
    while(true){
        int v = -1;
        for(int i = 1; i <= n; i ++){
            if(!vis[i] && (v == -1 || mincost[i] < mincost[v]))
                v = i;
        }
        if(v == -1) break;
        vis[v] = true;
        res += mincost[v];
        for(int i = 1; i <= n; i ++){
            mincost[i] = min(mincost[i], g[i][v]);
        }
    }
	return res;
}
int main() {
	while(scanf("%d%d%d",&c,&n,&m) != EOF) {
		init();
		for(int i = 1; i <= n; i ++) {
			int u, v, w;
			scanf("%d%d%d",&u,&v,&w);
			if(g[u][v] > w) {
				g[u][v] = g[v][u] = w;
			}
		}
		int ans = prim();
		if(ans > c) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int c, n, m;
struct Nod {
	int u, v, w;
}nod[N];
int fa[110], ans;
bool cmp(Nod a, Nod b) {
	return a.w < b.w;
}
void init() {
	for(int i = 0; i < 110; i ++) fa[i] = i;
	ans = 0;
}
int find(int x) {
	return fa[x] == x ? x: find(fa[x]);
}
void uni(int x, int y) {
	x = find(x), y = find(y);
	if(x > y) fa[x] = y;
	else fa[y] = x;
}
int main() {
	while(scanf("%d%d%d",&c,&n,&m) != EOF) {
		init();
		for(int i = 0; i < n; i ++) {
			cin >> nod[i].u >> nod[i].v >> nod[i].w;
		}
		sort(nod,nod+n,cmp);
		for(int i = 0; i < n; i ++) {
			if(find(nod[i].u) != find(nod[i].v)) {
				ans += nod[i].w;
				uni(nod[i].u,nod[i].v);
			}
		}
		if(ans > c) printf("No\n");
		else printf("Yes\n");
	}
}