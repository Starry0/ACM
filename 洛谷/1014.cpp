#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x = 1, y;
	cin >> n;
	for(x = 1; ; x ++) {
		if(x*(x+1)/2 < n && (x+1)*(x+2)/2 >= n) break;
	}
	if(x&1) {
		n -= x*(x+1)/2+1;
		y = x+1; x = 1;
		while(n) {
			x++;y--;
			n--;
		}
	} else {
		n -= x*(x+1)/2+1;
		x++ ; y = 1;
		while(n) {
			x--;y++;
			n--;
		}
	}
	printf("%d/%d\n",x,y);
	return 0;
}