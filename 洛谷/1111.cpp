#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int M = 100010;
const int N = 1010;
int n, m, fa[N];
struct Nod {
	int x, y, t;
}nod[M];
bool cmp(Nod a, Nod b) {
	return a.t < b.t;
}
int find(int x) {
	return fa[x] == x? fa[x]: find(fa[x]);
}
void unit(int x, int y) {
	x = find(x), y = find(y);
	if(x < y) fa[x] = y;
	else fa[y] = x;
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		cin >> nod[i].x >> nod[i].y >> nod[i].t;
	}
	sort(nod,nod+m,cmp);
	for(int i = 0; i < N; i ++) fa[i] = i;
	for(int i = 0; i < m; i ++) {
		if(find(nod[i].x) != find(nod[i].y)) {
			unit(nod[i].x,nod[i].y);
			n--;
		}
		if(n == 1) return 0*printf("%d\n",nod[i].t);
	}
	printf("-1\n");
	return 0;
}