#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int main() {
	int t, n, m;
	cin >> t;
	for(int ca = 1; ca <= t; ca ++) {
		cin >> n >> m;
		double ans1 = 0.5, ans2 = 1.0*(m+1)/(2*m);
		if(n == 1) ans1 = 1.0;
		if(m == 1) ans2 = 1.0;
		printf("Case #%d: %.6lf %.6lf\n",ca,ans1,ans2);
	}
	return 0;
}

// 1 2 3
// 1 3 2    
// 2 1 3    2
// 2 3 1    1
// 3 2 1    1
// 3 1 2    2