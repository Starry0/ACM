#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct Nod{
	int r[3];
}nod[N];

bool cmp(const Nod &a, const Nod &b) {
	return a.r[2] < b.r[2];
}
set<int> st[2];
int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i ++) {
			scanf("%d%d%d", &nod[i].r[0], &nod[i].r[1], &nod[i].r[2]);
		}
		int last = 0;
		st[0].insert(n-1);
		sort(nod,nod+n,cmp);
		set<int> :: iterator it;
		for(int i = n-2; i >= 0; i --) {
			last = 1 - last;
			for(it = st[1-last].begin(); it != st[1-last].end(); ++it) {
				int v = (*it);
				if(nod[v].r[0] < nod[i].r[0] || nod[v].r[1] < nod[i].r[1]) {
					st[last].insert(v);
				}
			}
			st[last].insert(i);
			st[1-last].clear();
		}
		cout << st[last].size() << endl;
	}
	return 0;
}