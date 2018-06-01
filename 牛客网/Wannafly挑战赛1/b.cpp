#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
int a[N], ans[1000100];
int main() {
	int n;scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	ll sum = 0;
	for(int i = 1; i <= n; i ++) {
		int tmp = 0;
		for(int j = i; j <= n; j ++) {
			tmp ^= a[j];
			if(ans[tmp]) sum += 1LL*ans[tmp];
		}
		tmp = 0;
		for(int j = i; j >= 1; j --) {
			tmp ^= a[j];
			ans[tmp] ++;
		}
	}
	printf("%lld\n",sum);
	return 0;
}