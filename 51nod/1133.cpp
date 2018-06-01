#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
struct Nod {
	int l, r;
}nod[N];
bool cmp(Nod a, Nod b) {
	if(a.r != b.r) return a.r < b.r;
	else return a.l < b.l;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &nod[i].l, &nod[i].r);
	}
	sort(nod+1, nod+1+n, cmp);
	int cnt = 2, ans = 1, r = nod[1].r;
	while(cnt <= n) {
		if(nod[cnt].l >= r) {
			ans++;
			r = nod[cnt].r;
		}
		cnt++;
	} 
	printf("%d\n",ans);
	return 0;
}