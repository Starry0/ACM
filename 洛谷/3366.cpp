#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10010;
const int M = 200010;
struct Nod{
	int x, y, z;
}e[M];
bool cmp(Nod a, Nod b) {
	return a.z < b.z;  
}
int fa[N];
int find(int x) {
	return fa[x] = (fa[x] == x ? fa[x]: find(fa[x]));
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) fa[i] = i;
	for(int i = 0; i < m; i ++) {
		scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z);
	}
	sort(e,e+m,cmp);
	ll ans = 0;
	for(int i = 0; i < m; i ++) {
		if(find(e[i].x) != find(e[i].y)) {
			ans += e[i].z;
			fa[find(e[i].x)] = find(e[i].y);
		}
	}
	cout << ans << endl;
	return 0;
}