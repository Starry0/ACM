#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int main() {
	ull l, r;
	cin >> l >> r;
	ull a = __gcd(l,r);
	cout << l/a*r<<endl;
	return 0;
}