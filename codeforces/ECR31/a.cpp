#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t, x, sum = 0;
	cin >> n >> t;
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		sum += (86400 - x);
		if(sum >= t) return 0*printf("%d\n",i);
	}
	return 0;
}