#include <bits/stdc++.h>
#define ll long long
ll a[12];
using namespace std;

int main() {
	ll a, b, ans = 1;
	cin >> a >> b;
	ll num = b - a;
	if(num >= 10) printf("0\n");
	else {
		for(ll i = a+1; i <= b; i ++) {
			ans = ans*i%10;
		}
		printf("%lld\n", ans);
	}
	return 0;
}