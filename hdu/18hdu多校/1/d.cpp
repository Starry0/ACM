#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
struct Nod{
	int l, r;
}e[N];

bool cmp(const Nod &a, const Nod &b) {
	if(a.l != b.l) return a.l < b.l;
	else return a.r > b.r;
}
int main() {
	int t, n, m, l, r;
	cin >> t;
	while(t--) {
		set<int> st;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i ++) st.insert(i);
		for(int i = 1; i <= m; i ++) scanf("%d%d", &e[i].l, &e[i].r);
		sort(e+1,e+1+m,cmp);
		int l = 1, r = 0;
		for(int i = 1; i <= m; i ++) {
			if(e[i].r <= r) continue;
			if(e[i].l > r) {
				while(e[i].l > r) a[++r] = 1;
				while(l < e[i].l) st.insert(a[l++]);
				if((*st.begin()) == 1) st.erase(st.begin());
				while(r < e[i].r) {
					a[++r] = (*st.begin());
					st.erase(st.begin());
				}
			} else if(e[i].l <= r) {
				while(l < e[i].l) st.insert(a[l++]);
				while(r < e[i].r) {
					a[++r] = *st.begin();
					st.erase(st.begin());
				}
			}
		}
		while(r < n) a[++r] = 1;
		for(int i = 1; i <= n; i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}