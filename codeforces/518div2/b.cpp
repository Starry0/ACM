#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll a, b, ans = 0;
	cin >> b;
	for(ll i = 1; i*i <= b; i ++) {
		if(i*i == b) ans++;
		else if(b%i == 0) ans += 2;
	}
	cout << ans << endl;
	return 0;
}