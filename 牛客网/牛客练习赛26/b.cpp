#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
double p[N];
double dp[1010];
int main() {
	int n, k;
	scanf("%d%d",&n, &k);
	double ans = 0;
	for(int i = 1; i <= n; i ++) scanf("%lf",&p[i]), ans += p[i];
	dp[0] = 1;
	for(int i = 1; i <= n; i ++) {
		for(int j = k; j >= 0; j --) {
			dp[j] = dp[j]*(1-p[i])+dp[j-1]*p[i];
		}
	}
	printf("%.4f\n%.4lf",ans,dp[k]);
	return 0;
}