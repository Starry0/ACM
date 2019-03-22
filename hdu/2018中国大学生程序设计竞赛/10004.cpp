#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N = 1e5+10;
using namespace std;
int main() {
	ll t, n, a, b, c;
	cin >> t;
	while(t--) {
		cin >> n >> a;
		if(n == 2) {
			if(a&1) {
				ll tmp = a/2;
				c = n*n+(n-1)*(n-1);
				b = c-1;
			} else {
				ll tmp = a/2-1;
				c = 1 + (n-1)*(n-1);
				b = c - 2;
			}
			if(b <= 1e9 && c <= 1e9)
				cout << b << ' ' << c << endl;
			else cout << "-1 - 1\n";
		} else cout << "-1 -1\n";
	}
 	return 0;
}