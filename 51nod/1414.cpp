#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e4+10;
int a[N], n;
int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
		int MAX = -INF;
		for(int i = 1; i <= n; i ++) {
			if(n%i == 0 && n/i >= 3) {
				for(int j = 0; j < i; j ++) {
					int ans = 0;
					for(int k = j; k < n; k += i) {
						ans += a[k];
					}
					MAX = max(MAX, ans);
				}
			}
		}
		printf("%d\n",MAX);
	}
	return 0;
}