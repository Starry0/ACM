#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
struct Nod{
	ll l, r, c, p;
}e[N];
bool cmp(const Nod &a, const Nod &b) {
	if(a.l == b.l) return a.r < b.r;
	else return a.l < b.l;
}
bool operator > (Nod a, Nod b) {
	return a.p > b.p;
};
int main() {
	ll n, k, m;
	cin >> n >> k >> m;
	for(int i = 0; i < m; i ++) cin >> e[i].l >> e[i].r >> e[i].c >> e[i].p;
	sort(e,e+m,cmp);
	set<Nod> st;
	// priority_queue<Nod, vector<Nod>,greater<Nod> > que, que1;
	// int l = 0;
	// ll ans = 0;
	// for(int i = 1; i <= n; i ++) {
	// 	while(l < m && e[l].l <= i) st.insert(e[i]);
	// 	ll res = 0;
	// 	while(que.size()) {
	// 		Nod nod = que.top();
	// 		que.pop();
	// 		if(nod.r < i ) continue;
	// 		if(nod.r != i)que1.push(nod);
	// 		if(res+nod.c >= k) {
	// 			ans += (k-res)*nod.p;
	// 			break;
	// 		} else {
	// 			ans += nod.c*nod.p;
	// 			res += nod.c;
	// 		}
	// 	}
	// 	while(que1.size()) que.push(que1.top()), que1.pop();
	// }
	// cout << ans << endl;
	return 0;
}