#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int main() {
	int t;
	double d, v;
	double PI = acos(-1);
	cin >> t;
	while(t--) {
		cin >> d;
		if(d == 0) {
			printf("0.00000\n");
			continue;
		}
		if(d >= 1) {
			v = PI*d;
			double h = (2*PI-v)/(PI/2.0);
			double a = sqrt(h*h+4)/2.0;
			printf("%.3lf %.3lf %.3lf\n",h,a,v );
			printf("%.5lf\n",PI*a);
		} else {
			
		}
	}
	return 0;
}