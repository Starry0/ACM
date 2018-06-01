#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		if(n%7 == 0 || (n-2)%7 == 0) puts("B");
		else puts("A");
	}
	return 0;
}