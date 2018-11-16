#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, l, A, B;
	cin >> A >> B >> l;	
	double c = 1.0*A/B;
	double pos = 0x3f3f3f3f;
	for(int i = 1; i <= l; i ++) {
		for(int j = 1; j <= l; j ++) {
			double C = 1.0*i/j;
			if(C >= c && __gcd(i,j) == 1 && C < pos) {
				pos = C;
				a = i; b = j;
			}
		}
	}
	cout << a << ' ' << b << endl;
	return 0;
}