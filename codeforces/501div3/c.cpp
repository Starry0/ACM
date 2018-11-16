#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
struct Nod{
	ll a, b;
}e[N];
int a[N], b[N];
bool cmp(const Nod &a, const Nod &b) {
	return (a.a-a.b) > (b.a-b.b);
}
int main() {
	ll n, m, sum = 0, ans = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i ++) cin >> e[i].a >> e[i].b, sum += e[i].a;
	sort(e,e+n,cmp);
	for(int i = 0; i < n; i ++) {
		if(sum <= m) break;
		sum -= (e[i].a-e[i].b);
		ans++;
	}
	if(sum > m) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}