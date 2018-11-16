#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n < 0) {
		cout << '-';
		n = -n;
	}

	bool flag = 1;
	while(n) {
		int x = n%10;
		n /= 10;
		if(flag&&x==0) continue;
		else if(flag) {
			cout << x;
			flag = 0;
		} else cout << x;
	}
	return 0;
}