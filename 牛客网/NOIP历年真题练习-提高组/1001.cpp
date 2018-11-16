#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
int fa[N];
struct Nod {
	double x, y, z;
}e[N];
int find(int x) {
	return fa[x] = (fa[x] == x ? x: find(fa[x]));
}
double dist(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
}
int main() {
	ll t, n, h, r;
	cin >> t;
	while(t--) {
		cin >> n >> h >> r;
		for(int i = 1; i <= n+2; i ++) fa[i] = i;
		for(int i = 1; i <= n; i ++) {
			cin >> e[i].x >> e[i].y >> e[i].z;
			for(int j = 1; j < i; j ++) {
				if(dist(e[i].x,e[i].y,e[i].z,e[j].x,e[j].y,e[j].z) <= 2.0*r) {
					fa[find(i)] = find(j);
				}
			}
			if(e[i].z <= r) fa[find(n+1)] = find(i);
			if(h-e[i].z <= r) fa[find(n+2)] = find(i);
		}
		if(find(n+1) == find(n+2)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}