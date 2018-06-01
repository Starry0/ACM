#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, ans = 0;
	cin >> n >> x;
	for(int i = 1; i <= n; i ++) {
		int tmp = i;
		while(tmp) {
			if(tmp%10 == x) ans ++;
			tmp /= 10;
		}
	}
	printf("%d\n",ans);
	return 0;
}