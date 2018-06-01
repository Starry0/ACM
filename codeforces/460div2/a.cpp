#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, x, y;
	double ans = 1e9;
	cin >> n >> m;
	for(int i = 0; i < n; i ++) {
		cin >> x >> y;
		ans = min(ans,1.0*x/y);
	}
	printf("%.8f\n",ans*m);
	return 0;
}