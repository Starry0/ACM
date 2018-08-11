#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;

int main() {
	int t;
	double PI = acos(-1);
	cin >> t;
	double a, b, c;
	while(t--) {
		cin >> a >> b;
		double c = a*PI+2*b-0.0000005;
		if(c < 0) c = 0;
		printf("%.6lf\n",c);
	}
	return 0;
}   	