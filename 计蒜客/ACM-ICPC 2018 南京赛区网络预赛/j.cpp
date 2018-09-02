#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e7+1;
int f[N], sum[N], cnt;
bool vis[N];
void init() {
	memset(vis,1,sizeof(vis));
	for(int i = 2; i*i < N; i ++) {
		for(int j = i*i; j < N; j += i*i) {
			vis[j] = 0;
		}
	}
	for(int i = 1; i < N; i ++) {
		if(vis[i]) {
			sum[i] = sum[i-1]+1;
			f[cnt++] = i;
		} else sum[i] = sum[i-1];
	}
}

int main() {
	int t, n;
	init();
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		ll ans = 0LL;
		for(int i = 0; i < cnt && f[i] <= n; i ++) {
			int res = (int)(n/f[i]);
			ans += sum[res];
		}
		printf("%lld\n",ans);
	}
	return 0;
}