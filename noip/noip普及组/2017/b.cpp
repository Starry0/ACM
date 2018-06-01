#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main() {
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a,a+n);
	while(q--) {
		int len, y, flag = 0;
		cin >> len >> y;
		for(int i = 0; i < n; i ++) {
			int len1 = log10(a[i]) + 1;
			if(len1 >= len) {
				int ans = 10, j = 0;
				for(j = 0; j < len; j ++) {
					if((a[i]%ans) == (y%ans)) ans *= 10;
					else break;
				}
				if(j == len) flag = 1;
			}
			if(flag) {
				printf("%d\n",a[i]);
				break;
			}
		}
		if(!flag) printf("-1\n");
	}
	return 0;
}