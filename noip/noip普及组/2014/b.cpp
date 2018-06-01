#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, aa, bb, ans1, ans2;
	cin >> a >> b >> c;
	aa = bb = ans2 = 1; ans1 = c;
	while(aa <= c && bb <= c) {
		if(aa*b >= a*bb) {
			if(aa * ans2 < bb * ans1) {
				ans1 = aa; ans2 = bb;
				//printf("%d ==%d\n", ans1, ans2);
			}
			bb++;
		} else {
			aa++;
		}
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}