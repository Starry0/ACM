#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	int n, x, y;
	x = y = INF;
	cin >> n;
	for(int i = 1; i <= sqrt(n); i ++) {
		if(i+(n-1)/i+1 < x + y) {
			x = i;
			y = (n-1)/i+1;
		}
	}
	for(int i = x; i >= 1; i --) {
		for(int j = 0; j < y; j ++) {
			int ans = (i-1)*y+1+j;
			if(1 <= ans && ans <= n)printf("%d ",ans);
		}
	}
	printf("\n");
	return 0;
}