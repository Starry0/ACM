#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;

int main() {
	double l, k, a, b;
	cin >> l >> k >> a >> b;
	double t1 = l/a, t2;
	if(a <= b) t2 = l/b;
	else {
		t2 = min(l/b,k/(a-b)*2);
	}
	// printf("%.2lf %.2lf\n",t1,t2 );
	printf("%.2f\n",t2-t1);
    return 0;
}
