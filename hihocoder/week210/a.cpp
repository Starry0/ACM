#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10010;
int a[N], p[N], M[N];
struct Nod{
	int p, w;
}e[N*2];

bool cmp(const Nod &a, const Nod &b) {
	return a.p > b.p;
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++) cin >> a[i];
	for(int i = 0; i < m; i ++) cin >> p[i];
	for(int i = 0; i < m; i ++) cin >> M[i];
	int cnt = 0;
	for(int i = 0; i < m; i ++) {
		if(a[i] >= M[i]) {
			e[cnt].p = M[i]*p[i];
			e[cnt++].w = a[i]/M[i];
			a[i] -= a[i]/M[i]*M[i];
		}
		if(a[i]) e[cnt].p = a[i]*p[i], e[cnt++].w = 1;
	}
	ll ans = 0;
	sort(e,e+cnt,cmp);
	for(int i = 0; i < cnt; i ++) {
		if(n >= e[i].w) {
			ans += 1LL*e[i].p*e[i].w;
			n -= e[i].w;
		} else if(n < e[i].w) {
			ans += 1LL*n*e[i].p;
			break;
		}
	}	
	cout << ans << endl;
	return 0;
}