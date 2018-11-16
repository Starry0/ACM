#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll n;
	while(cin >> n) {
		cout << (n*n*n*n-6*n*n*n+23*n*n-18*n+24)/24<< endl;
	}
	return 0;
	
}
