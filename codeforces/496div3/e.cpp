#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int a[N], n, m, k;
map<int,ll> mp;
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		if(a[i] == m) k = i;
	}
	int s = 1;
	for(int i = k; i > 0; i --) {
		if(a[i] > m) s++;
		else s--;
		mp[s]++;
	}
	s = -1;
	ll ans = 0;
	for(int i = k; i <= n; i ++) {
		if(a[i] > m) s--;
		else s++;
		ans += mp[s] + mp[s+1];
	}
	printf("%lld\n",ans);
	return 0;
}