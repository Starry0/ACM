#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll x, y, z, ans = 0;	
	cin >> x >> y;
	z = x*y;
	for(ll i = 2; i < sqrt(z); i ++) {
		if(z%i == 0) {
			if(__gcd(i,z/i) == x && z/__gcd(i,z/i) == y) {
				if(i == z/i) ans++;
				else ans += 2;
			}
		}
	}
	cout << ans << endl;
	return 0;
}