#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1010;
int d[N], c[N], b, t, n;
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &b);
		for(int i = 1; i <= n; i ++) scanf("%d", &c[i]);
		for(int i = 2; i <= n; i ++) scanf("%d", &d[i]);
		int ans = c[1];
		for(int i = 2; i <= n; i ++) {
			ans -= b*d[i];
			if(ans < 0){
				printf("No\n");
				goto tt;
			}
			ans += c[i];
		}
		printf("Yes\n");
		tt:;
	}
	return 0;
}