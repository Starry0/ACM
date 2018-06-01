#include <bits/stdc++.h>
using namespace std;
int a[6], b[6];
int main() {
	for(int i = 1; i <= 5; i ++) {
		cin >> a[i];
		b[i] = a[i];
	}
	int ans = 0;
	while(a[4] > 0) {
		if(a[1] > a[5] && (a[1]-a[5]+a[3]) > a[5] || a[2] >= a[4]) a[4] -= a[2];
		else a[1] += a[3];
		a[1] -= a[5];
		ans ++;
	}
	printf("%d\n",ans);
	while(b[4] > 0) {
		if(b[1] > b[5] && (b[1]-b[5]+b[3]) > b[5] || b[2] >= b[4]) {
			b[4] -= b[2];
			printf("STRIKE\n");
		} else {
			b[1] += b[3];
			printf("HEAL\n");
		}
		b[1] -= b[5];
		ans ++;
	}
	return 0;
}