#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const int N = 110;
int a[N];
int main() {
	int n;
	while(scanf("%d", &n) &&n) {
		int s, t, k;
		for(int i = 1; i <= n; i ++) {
			scanf("%d %d %d", &s, &t, &k);
			for(int j = s; j < t; j ++) {
				a[j] += k;
			}
		}
		int ans = 0;
		for(int i = 1; i <= 100; i ++) {
			ans = max(ans, a[i]);
		}
		printf("%d\n",ans);
		memset(a, 0, sizeof(a));
	}
	printf("*\n");
	return 0;
}