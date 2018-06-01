#include <iostream>
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int a, b, k;
void solve() {
	printf("%.3f\n",1.0*b/(a+b));
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> a >> b >> k;
		solve();
	}
	return 0;
}