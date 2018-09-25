#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+10;
const int mod = 1e9+7;
ll cnt[N];
int inv[30], t, n, q, v, c;

int main() {
	inv[0] = 1;
	for(int i = 1; i < 30; i ++) inv[i] = inv[i-1]*2;
	scanf("%d", &t);
	while(t--) {
		memset(cnt, 0, sizeof(cnt)); cnt[0] = 1;
		scanf("%d%d", &n, &q);
		for(int i = 0; i < n; i ++) {
			scanf("%d%d",&v,&c);
			for(int j = 0; j < c; j ++) {
				for(int k = N-1; k >= inv[j]*v; k--) {
					cnt[k] = (cnt[k] + cnt[k-inv[j]*v])%mod;
				}
			}
		}
		while(q--) {
			int s;
			scanf("%d", &s);
			printf("%lld\n", cnt[s]);
		}
	}
	return 0;
}