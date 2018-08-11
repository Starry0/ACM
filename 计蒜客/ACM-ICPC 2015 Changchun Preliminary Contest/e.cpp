#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n, m, t, q, x, y, sum[N], fa[N], cnt[N];
set<int> st;
struct Nod{
	int from, to, w;
}e[N];
bool cmp(Nod a, Nod b) {
	return a.w < b.w;
}
int find(int x) {
	return fa[x] = (fa[x] == x ?x: find(fa[x]));
}
void unite(int x, int y) {
	x = find(x), y = find(y);
	if(x > y) fa[x] = y;
	else fa[y] = x;
}
int bin(int x) {
	int l = 1, r = m;
	while(l < r) {
		int mid = (l+r)>>1;
		if(e[mid].w <= x) l = mid+1;
		else r = mid;
	}
	return r-1;
}

int main() {
	cin >> t;
	while(t--) {
		scanf("%d%d%d", &n, &m, &q);
		st.clear();
		for(int i = 1; i <= n; i ++) fa[i] = i, cnt[i] = 1;
		for(int i = 1; i <= m; i ++) scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].w);
		sort(e+1,e+1+m,cmp);
		for(int i = 1; i <= m; i ++) {
			x = find(e[i].from), y = find(e[i].to);
			if(x != y) {
				sum[i] = sum[i-1];
				if(st.count(x)) sum[i] -= cnt[x]*(cnt[x]-1);
				if(st.count(y)) sum[i] -= cnt[y]*(cnt[y]-1);
				sum[i] += (cnt[x]+cnt[y])*(cnt[x]+cnt[y]-1);
				st.insert(min(x,y));
				st.erase(max(x,y));
				cnt[min(x,y)] += cnt[max(x,y)];
				cnt[max(x,y)] = 0;
				unite(x,y);
			} else sum[i] = sum[i-1];
		}
		// for(int i = 1; i <= m; i ++) printf("%d ",sum[i]);printf("\n");
		while(q--) {
			scanf("%d", &x);
			if(x >= e[m].w) printf("%d\n",sum[m]);
			else printf("%d\n",sum[bin(x)]);
		}
	}
	return 0;
}