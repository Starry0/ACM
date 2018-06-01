#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n, m;
int main() {
	cin >> n >> m;
	if(n >= 30) cout << m << endl;
	else {
		int ans = 1;
		for(int i = 1; i <= n; i ++) {
			ans *= 2;
		}
		cout << m % ans << endl;
	}
	return 0;
}