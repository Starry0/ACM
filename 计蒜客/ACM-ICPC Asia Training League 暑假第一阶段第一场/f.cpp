#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		if(n > 180) n -= 180;
		n = int(1.0*n/10+0.5);
		if(n == 0) n = 18;
		printf("%02d\n",n);
	}
	return 0;
}