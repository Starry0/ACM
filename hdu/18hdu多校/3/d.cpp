#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int main() {
	ll t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		if(n == 1) printf("5\n");
		else printf("%lld\n",n+5);
	}
	return 0;
}