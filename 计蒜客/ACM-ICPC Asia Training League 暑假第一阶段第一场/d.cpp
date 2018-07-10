#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1510;
int a[N], ans[N], sum[N], sum1[N];
int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			ans[i] = 0;
		}
		for(int i = n-1; i >= 1; i --) ans[i] = ans[i+1] + a[i+1];
		for(int i = 1; i <= n; i ++) {
			sum[i] = sum[i-1] + a[i];
		}
		for(int i = 1; i  <= n; i ++) {
			sum1[i] = sum1[i-1] + sum[i-1];
		}
		for(int i = 1; i <= n; i ++) printf("%3d%c",ans[i]," \n"[i==n]);
		for(int i = 1; i <= n; i ++) printf("%3d%c",sum1[i]," \n"[i==n]);
		int tmp = 0;
		for(int i = 1; i <= n; i ++) {
			int ans1 = sum[i-1];
		}
	}
	return 0;
}