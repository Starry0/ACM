#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j < i; j ++) {
				ans += __gcd(i+j,i-j)==1;
			}
		}
		cout << ans << endl;
	}	
	return 0;
}