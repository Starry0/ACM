#include <bits/stdc++.h>
using namespace std;
const int N = 10100;
int n, q, a[N];
bool ok(int x, int y, int yy) {
	for(int i = 1; i <= x; i ++) {
		if(y == 0 || yy == 0) return false;
		if(y%10 != yy%10) return false;
		y /= 10; yy /= 10;	
	}
	return true;
}
int main() {
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	while(q--) {
		int MIN = 1e8, x, y;
		scanf("%d%d", &x, &y);
		for(int i = 1; i <= n; i ++) {
			if(ok(x,y,a[i])) {
				MIN = min(MIN, a[i]);
			}
		}
		printf("%d\n",MIN==1e8?-1:MIN);
	}
	return 0;
}