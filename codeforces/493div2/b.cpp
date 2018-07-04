#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int a[N], b[N], n, B;
int dp[N];
int main() {
	cin >> n >> B;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int ans1 = 0, ans2 = 0, cnt = 0;
	for(int i = 1; i < n; i ++) {
		if(a[i]&1) ans1++;
		else ans2++;
		if(ans1 == ans2) {
			b[cnt++] = abs(a[i]-a[i+1]);
		}
	}
	for(int i = 0; i < cnt; i ++) {
		for(int j = B; j >= b[i]; j --) {
			dp[j] = max(dp[j], dp[j-b[i]]+1);
		}
	}
	cout << dp[B] << endl;
	return 0;
}
		
0101|0101|0101|01|01