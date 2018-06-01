#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N], b[N];
int main() {
	int n, x;
	cin >> n >> x;
	int res = 100, k = 0, x1 = x;
	while(x1) {
		a[k++] = x1 % 2;
		x1 /= 2;
	}
	int tmp;
	for(int i = 1; i <= n; i ++) {
		cin >> tmp;
		if((tmp | x) > x) {
			continue;
		}
		int kk = 0;
		while(tmp) {
			b[kk++] += tmp%2;
			tmp /= 2;
		}
	}
	k = 0;
	while(x) {
		if(b[k] == 0 && a[k] != 0) {
			res = 0;
			break;
		}
		if(b[k]) {
			res = min(res, b[k]);
		}
		k++;
		x /= 2;
	}
	printf("%d\n",res);
	return 0;
}