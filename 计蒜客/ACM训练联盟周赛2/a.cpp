#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
const int M = 1e5+10;
int a[N], b[N], fa[M];
vector<int> vs[N];
int find(int x) {
	return fa[x] = (fa[x] == x ? fa[x]: find(fa[x]));
}
int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= M; i ++) fa[i] = i;
		for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			if(a[i] != b[i]) {
				if(find(a[i]) != find(b[i])) {
					ans++;
					fa[find(a[i])] = find(b[i]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}