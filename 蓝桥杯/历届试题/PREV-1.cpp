#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int d = a/__gcd(a,b)*b;
	a = d/__gcd(d,c)*c;
	cout << a << endl;
	return 0;
}