#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int ans = 0;
	for(int i = 0; k; i += 4, k--) {
		ans += 2*(n-i)+2*(m-i)-4;
	}
	cout << ans << endl;
	return 0;
}