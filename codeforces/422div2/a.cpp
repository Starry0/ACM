#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int n = min(a, b);
	ll ans = 1;
	for(int i = 1; i <= n; i ++) {
		ans *= i;
	}
	printf("%lld\n",ans);
	return 0;
}
