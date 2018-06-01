#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
typedef long long LL;
const int MAXN = 500007;

struct Edge {
	int to, w;
	Edge* next;
};

Edge edges[MAXN * 2], * g[MAXN];
int nEdge;
int open[MAXN];
int a[MAXN];
bool vst[MAXN];
int hash[MAXN * 2];
int N, K;

inline void addEdge(int x, int y, int w) {
	Edge* p = &edges[nEdge++];
	p->to = y;
	p->w = w;
	p->next = g[x];
	g[x] = p;
}

void bfs() {
	int i, j, x, m = 0;
	Edge* p;

	memset(vst, false, N);
	open[m++] = 0;
	vst[0] = true;
	for (i = 0; i < m; ++i) {
		x = open[i];
		for (p = g[x]; p; p = p->next) {
			if (!vst[p->to]) {
				a[p->to] = (a[x] ^ p->w);
				vst[p->to] = true;
				open[m++] = p->to;
			}
		}
	}
	for (i = 0; i < N; ++i) {
		++hash[a[i]];
		assert(vst[i] == true);
	}
}

void input() {
	int i, x, y, w;

	scanf("%d%d", &N, &K);
	assert(2 <= N && N <= 500000);
	assert(0 <= K && K <= 500000);
	for (i = 0; i < N; ++i) {
		g[i] = NULL;
	}
	nEdge = 0;

	for (i = 0; i < N - 1; ++i) {
		scanf("%d%d%d", &x, &y, &w);
		assert(0 <= x && x < N);
		assert(0 <= y && y < N);
		assert(1 <= w && w <= 500000);
		addEdge(x, y, w);
		addEdge(y, x, w);
	}
}

void solve() {
	int i, j;
	LL ans = 0;

	bfs();
	for (i = 0; i < N; ++i) {
		ans += hash[a[i] ^ K];
	}
	if (K == 0) ans -= N;
	ans /= 2;
	printf("%I64d\n", ans);
	// clear the hash
	for (i = 0; i < N; ++i) {
		hash[a[i]] = 0;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	assert(T <= 50);
	while (T--) {
		input();
		solve();
	}
	return 0;
}
