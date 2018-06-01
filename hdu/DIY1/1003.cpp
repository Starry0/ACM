#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1010;
int a[N], ans[2*N];
int main() {
	int c;
	scanf("%d", &c);
	while(c--) {
		memset(ans, 0, sizeof(ans));
		int n, k;
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; i ++) {
			scanf("%d", &a[i]);
		}
		int cnt = 0;
		for(int i = 0; i < n; i ++) {
			for(int j = i+1; j < n; j ++) {
				ans[abs(a[i]-a[j])]++;
			}
		}
		int i;
		for(i = 0; ; i ++) {
			if(ans[i] > 0) {
				k--;
			}
			if(k <= 0) break;
		}
		printf("%d\n",i);
	}
	return 0;
}
