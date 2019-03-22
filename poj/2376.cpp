#include <iostream>
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 25010;
struct Nod{
	int l, r;
}e[N];
bool cmp(Nod a, Nod b) {
	return a.l < b.l;
}
int main() {
	int t ,n;
	cin >> n >> t;
	for(int i = 0; i < n; i ++) cin >> e[i].l >> e[i].r;
	sort(e,e+n,cmp);
	if(e[0].l > 1) return 0*printf("-1\n");
	int x = 1, i = 0, ans = 0, y = 0;
	while(i < n) {
		while(i < n && e[i].l <= x) {
			y = max(y,e[i].r);
			i++;
		}
		if(y+1 == x) return 0*printf("-1\n");
		ans++;
		x = y+1;
		if(y >= t) break;
	}
	if(y >= t)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}