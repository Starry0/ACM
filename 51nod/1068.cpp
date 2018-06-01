#include <bits/stdc++.h>
using namespace std;
char str[1010];
int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> str;
		int ans = 0;
		for(int i = 0; str[i]; i ++) {
			ans += str[i] - '0';
		}
		if(ans % 3 == 0)puts("B");
		else puts("A");
	}
	return 0;
}							