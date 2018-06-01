#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	while(n--) {
		int s, d;
		cin >> s >>d;
		while(ans >= s) s += d;
		ans = s;
	}
	printf("%d\n",ans);
	return 0;
}