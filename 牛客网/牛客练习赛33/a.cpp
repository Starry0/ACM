#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int main() {
	ll l, r, x, t;
	cin >> t;
	while(t--) {
		cin >> l >> r >> x;
		printf("%lld\n",r/x-(l-1)/x);	
	}
	return 0;
}