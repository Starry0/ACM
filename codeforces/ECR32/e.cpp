#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1<<18;
ll a[40], b[40], c[N], d[N], k, ans, sum, n, m;
void dfs(int x) {
	if(x == ans + 1) {
		c[++k] = sum%m;
		return ;
	}
	sum += b[x]; dfs(x + 1);
	sum -= b[x]; dfs(x + 1);
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i], a[i] %= m, b[i] = a[i];
	ans = n/2;
	dfs(1);
	ll n1 = k;
	for(int i = 1; i <= k; i ++) d[i] = c[i];
	memset(c, 0, sizeof(c));
	ans = n; k = 0;
	dfs(n/2+1);
	ll MAX = -1;
	sort(d+1,d+n1+1);
	for(int i = 1; i <= k; i ++) {
        int t = lower_bound(d+1,d+n1,m-c[i]-1)-d;  
        while(c[i]+d[t]>=m)t--;  
        MAX=max(MAX,c[i] + d[t]);  
	}
	printf("%lld\n",MAX);
	return 0;
}