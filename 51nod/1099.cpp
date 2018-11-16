#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int main() {
	int n, s = 0, MIN = N, x, y;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> x >> y; s += y;
		MIN = min(x-y,MIN);
	}
	printf("%d\n",s+MIN);
	return 0;
}