#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m = 0;
	cin >> n;
	if(n < 0) {
		cout << '-';
		n = -n;
	}
	while(n) {
		m = m*10+n%10;
		n /= 10;
	}
	cout << m << endl;
	return 0;
}