#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int ans = 0, ans1 = 0;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		if(x < 0) ans++;
		else ans1++;
	}
	if(ans <= 1 || ans1 <= 1) printf("Yes\n");
	else printf("No\n");
	return 0;
}