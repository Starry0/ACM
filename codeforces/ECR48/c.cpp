#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5+10;
ll a[2][N], s[N], sum[2][N];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) scanf("%lld", &a[0][i]);
	for(int i = 1; i <= n; i ++) scanf("%lld", &a[1][i]);
	for(int i = 1; i <= n; i ++) s[i] = s[i-1] + a[0][i] + a[1][i];
	sum[0][n] = a[1][n];
	sum[1][n] = a[0][n];
	for(int i = n-1; i >= 1; i --) {
		sum[0][i] = sum[0][i+1] + s[n] - s[i] + ((n-i+1)*2-1)*a[1][i];
		sum[1][i] = sum[1][i+1] + s[n] - s[i] + ((n-i+1)*2-1)*a[0][i];
	}
	// for(int i = 0; i < 2; i ++) {
	// 	for(int j = 1; j <= n; j ++) printf("%d ", sum[i][j]);
	// 	printf("\n");
	// }
	ll ans = sum[0][1], cnt = 0;
	for(int i = 1; i <= n; i ++) {
		if(i&1) {
			cnt += (a[0][i]*(2*i-2)+a[1][i]*(2*i-1));
			ans = max(ans, cnt+sum[1][i+1]+(s[n]-s[i])*(2*i));
			// printf("%d %d %d %d\n",i,cnt,sum[1][i] );
		} else {
			cnt += (a[0][i]*(2*i-1)+a[1][i]*(2*i-2));
			ans = max(ans, cnt+sum[0][i+1]+(s[n]-s[i])*(2*i));
		}
	}
	cout << ans << endl;
	return 0;
}
// 6
// 12 8 12 17 20 5
// 17 4 8 8 8 4
// 631 350 232 114 37 4
// 722 496 342 196 74 5
// 635


// 0  49 97  304  464	631
// 17 25 137 185  536  576