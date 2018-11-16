#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		int tmp = i;
		while(tmp) {
			if(tmp%10==x) ans++;
			tmp /= 10;
		}
	}
	cout << ans<<endl;
	return 0;
}