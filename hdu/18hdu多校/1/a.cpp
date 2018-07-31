#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
int main() {
	ll t, n, x, y, z;
	cin >> t;
	while(t--) {
		scanf("%lld", &n);
		if(n*n*n%27==0) printf("%lld\n",n*n*n/27);
		else if(n*n*n%32==0) printf("%lld\n",n*n*n/32);
		else if(n*n*n%36==0) printf("%lld\n",n*n*n/36);
		else printf("-1\n");
	}
	return 0;
}