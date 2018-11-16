#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 500010;

struct Nod{
	int v, u, w;
}e[N];

bool cmp(Nod &a, Nod &b) {
	return a.w < b.w;
}
int fa[N];

int find(int x) {
	return fa[x] = (fa[x] == x ? x: find(fa[x]));
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) fa[i] = i;
	for(int i = 0; i < m; i ++) {
		scanf("%d%d%d", &e[i].v,&e[i].u,&e[i].w);
	}
	sort(e,e+n,cmp);
	ll ans = 0;
	for(int i = 0; i < m; i ++) {
		if(find(e[i].v) != find(e[i].u)) {
			ans += 1LL*e[i].w;
			fa[find(e[i].u)] = find(e[i].v);
		}
	}
	printf("%lld\n",ans);
    return 0;
}
