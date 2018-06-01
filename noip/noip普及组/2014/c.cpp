#include <bits/stdc++.h>
using namespace std;

int main() {
	int i, j, n, x = 1, y = 1, ans = 1;
	cin >> n >> i >> j;
	if(i == x) {
			return 0*printf("%d\n",ans + (j-y));
	} else {
		y += (n-1);
		ans += (n-1);
	}
	if(j == y) {
		return 0*printf("%d\n",ans+(i-x));
	} else {
		x += (n-1);
		ans += (n-1);
	}
	if(i == x) {
		return 0*printf("%d\n",ans+(y-i));
	} else {
		y -= (n-1);
		ans += (n-1);
	}
	n--;
	while(n >= 1) {
		if(j == y) {
			return 0*printf("%d\n",ans + (x-i));
		} else {
			x -= (n-1);
			ans += (n-1);
		}
		if(i == x) {
			return 0*printf("%d\n",ans+(j-y));
		} else {
			y += (n-1);
			ans += (n-1);
		}
		n--;
		if(j == y) {
			return 0*printf("%d\n",ans+(i-x));
		} else {
			ans += (n-1);
			x += (n-1);
		}
		if(i == x) {
			return 0*printf("%d\n", ans+(y-j));
		} else {
			ans += (n-1);
			y -= (n-1);
		}
		n--;
	}
	return 0;
}
/*

1  2  3  4  5  6
20 21 22 23 24 7
19 32 33 34 25 8
18 31 36 35 26 9
17 30 29 28 27 10
16 15 14 13 12 11
	*/	   