#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100010;
ll a[N], b[N], x, y, z, n, m, pre;
int main() {
	cin >> n >> m;
	cin >> pre;
	for(int i = 1; i < m; i ++) {
		cin >> x;
		if(x > pre) a[pre]++, a[x]--;
		else a[x]++, a[pre]--;
		pre = x;
	}
	ll sum = 0, ans = 0;
	for(int i = 1; i < n; i ++) {
		sum += a[i];
		// printf("--%d %lld---\n",i,sum);
		cin >> x >> y >> z;
		ans += min(sum*x,z+y*sum);
	}
	cout << ans << endl;
	return 0;
}