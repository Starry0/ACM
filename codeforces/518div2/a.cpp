#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll n, m, k, l, a;
	cin >> n >> m >> k >> l;
	if((k+l)%m == 0) a = k+l;
	else a = k+l+m-(k+l)%m;
	if(a > n) printf("-1\n");
	else printf("%lld\n",a/m);
	return 0;
}