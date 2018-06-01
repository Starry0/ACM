#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, sum = 0, tmp;
	cin >> n >> x;
	for(int i = 1; i <= n; i ++) {
		cin >> tmp;
		sum += tmp;
	}
	if(sum + n - 1 == x) printf("YES\n");
	else printf("NO\n");
	return 0;
}