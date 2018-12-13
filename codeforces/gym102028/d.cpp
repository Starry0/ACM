#include <bits/stdc++.h>
#define ll long long
using namespace std;
const double PI = 3.1415926535;

int main() {
	int t;
	cin >> t;
	while(t--) {
		double a, b, r, d;
		cin >> a >> b >> r >> d;
		double aa = atan(b/(a+r));
		d = d*PI/180.0;
		double ans = sqrt(b*b+(a+r)*(a+r));
		if(d >= aa) {
			printf("%.9lf\n",ans-r);
		} else {
			printf("%.9lf\n",ans*cos(d-aa)-r);
		}
	}
	return 0;
}