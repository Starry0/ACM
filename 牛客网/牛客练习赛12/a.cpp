#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t ;
	double pi = 3.1415926535;
	while(t--) {
		double a, b;
		cin >> a >> b;
		if(a > b) {
			if(a-b < b+2*pi-a) {
				cout << "clockwise\n";
			}else cout << "counterclockwise\n";
		}else {
			if(a+2*pi-b < b-a)  {
				cout << "clockwise\n";
			}else cout << "counterclockwise\n";
		}
	}
	return 0;
}