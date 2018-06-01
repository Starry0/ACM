#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int res = 0;
	while(n) {
		res = max(res, n%10);
		n /= 10;
	}
	printf("%d\n",res);
	return 0;
}