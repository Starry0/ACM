#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 52510;
int d[N];
ll sum[N];
struct Nod {
	int u, v, w;
}nod[22];
int main() {
	cout << INT_MAX << endl;
	int n, m, q, x, y;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &d[i]);
		sum[i] += 1LL*d[i];
	}
	for(int i = 1; i <= m; i ++) {
		scanf("%d %d %d", &nod[i].u, &nod[i].v, &nod[i].w);
	}
	cin >> q;
	while(q--) {
		int x, y;
		scanf("%d %d", &x, &y);

	}
	return 0;
}