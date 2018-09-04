#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
	for(int i = 2; i <= sqrt(x); i ++) {
		if(x%i == 0) return 0;
	}
	return 1;
}
int main() {
	int n, ans = 0;
	cin >> n;
	for(int i = 2; i <= n; i ++) {
		if(isprime(i)) {
			int t = i;
			while(t <= n) ans++, t *= i;
		}
	}
	cout << ans << endl;
	return 0;
}