#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		for(int j = i; j <= n; j ++) {
			int x = i^j;
			if(x >= j && i+j > x && x <= n) ans++;
		}
	}
	cout << ans<<endl;
	return 0;
}

//