#include <bits/stdc++.h>
using namespace std;

struct Nod{
	int id, s;
}e[5010];

bool cmp(Nod a, Nod b) {
	if(a.s != b.s) return a.s > b.s;
	else return a.id < b.id;
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> e[i].id >> e[i].s;
	}	
	sort(e+1,e+1+n,cmp);
	m = min(m*3/2,n);
	while(m+1 <= n && e[m].s == e[m+1].s) m++;
	printf("%d %d\n",e[m].s,m);
	for(int i = 1; i <= m; i ++) printf("%d %d\n",e[i].id,e[i].s);
	return 0;
}