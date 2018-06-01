#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	cin >> x;
	x = x*1000+x;
	x /= 7;
	x /= 11;
	x /= 13;
	cout << x << endl;
	return 0;
}