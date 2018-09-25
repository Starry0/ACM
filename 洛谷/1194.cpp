#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N][N];

struct Nod{
	int u, v, w;
}e[N*N];
bool cmp(Nod a, Nod b) {
	return a.w < b.w;
}
int find(int x) {
	return fa[x] = (fa[x] == x ?x:find(fa[x]));
}
int main() {
	int a, b, cnt;
	cin >> a >> b;
	for(int i = 1)
	for(int i = 1; i <= b; i ++) {
		for(int j = 1; j <= b; j ++) {
			int w;
			cin >> w;
			e[cnt].u = i, e[cnt].v = j;
			e[cnt++].w = w;
		}
	}
	sort(e,e+cnt,cmp);
	int ans = 0;
	for(int i = 0; i < cnt; i ++) {
		if()
	}
	return 0;
}