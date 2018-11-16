#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 50001;
int a[N], t1, t2;
typedef pair<int,int> P;
vector<P> vs[N];
int d1[N], d2[N], d3[N], d4[N];
void dij(int s, int )
int main() {
	int n, m, k;
	memset(d1, INF, sizeof(d1));
	memset(d2, INF, sizeof(d2));
	memset(d3, INF, sizeof(d3));
	memset(d4, INF, sizeof(d4));
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i ++) scanf("%d", &a[i]);
	for(int i = 0; i < m; i ++) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		vs[v].push_back(P(u,w));
		vs[u].push_back(P(v,w));
	}
	scanf("%d%d", &t1, &t1);
	d1[1] = d2[1] = 0;
	dij(1, 1);
	return 0;
}