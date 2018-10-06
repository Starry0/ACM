#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5+10;
int n, a[N], w[N];
ll sum[N], sum1[N], sum2[N];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		scanf("%d",&a[i]);
		sum[i] += sum[i-1]+1LL*a[i];
		sum1[i] = sum[i-1] + 1LL*i*a[i];
	}
	for(int i = n; i >= 1; i --) {
		sum2[i] = sum2[i+1] + 1LL*(n-i+1)*a[i];
	}
	for(int i = 1; i <= n; i ++) scanf("%d",&w[i]);

	return 0;
}