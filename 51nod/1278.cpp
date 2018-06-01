#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 50010;
struct Nod{
	int l, r;
}nod[N];
bool cmp(Nod a, Nod b) {
	if(a.l != b.l) return a.l < b.l;
	else return a.r < b.r;
}
int main() {
	int n, r, p;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		scanf("%d %d", &p, &r);
		nod[i].l = p-r, nod[i].r = p+r;
	}
	sort(nod,nod+n,cmp);
	int ans = 0;
	for(int i = 0; i < n; i ++) {
		int l = i+1, r = n-1;
		while(l <= r) {
			int m = (l+r) >> 1;
			if(nod[i].r >= nod[m].l) l = m+1;
			else r = m-1;
		}
		ans += n-l;
	}
	printf("%d\n",ans);
	return 0;
}