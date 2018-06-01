#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll x, ll y) {
	return y ? gcd(y, x%y): x;
}
ll low(ll x, ll y) {
	return y/gcd(x, y) * x;
}
int main() {
	int n;
	cin >> n;
	ll x = 1, y;
	while(n--) {
		cin >> y;
		x = low(x, y);
	}
	cout << x << endl;
	return 0;
}