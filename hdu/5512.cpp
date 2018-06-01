#include <bits/stdc++.h>
using namespace std;
int t, n, a, b;

int main() {
	cin >> t;
	for(int i = 1; i <= t; i ++) {
		cin >> n >> a >> b;
		int ans = n/__gcd(a,b)-2;
		if(ans&1) printf("Case #%d: Yuwgna\n",i);
		else printf("Case #%d: Iaka\n",i);
	}
	return 0;
}