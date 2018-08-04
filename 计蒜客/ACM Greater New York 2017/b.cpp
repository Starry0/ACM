#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main() {
	ll p, k, b, tmp, n;
	cin >> p;
	while(p--)  {
		cin >> k >> b >> n;
		ll ans = 0;
		while(n) {
			tmp = n%b;
			ans += tmp*tmp;
			n /= b;
		}
		printf("%lld %lld\n",k,ans);
	}
	return 0;
}