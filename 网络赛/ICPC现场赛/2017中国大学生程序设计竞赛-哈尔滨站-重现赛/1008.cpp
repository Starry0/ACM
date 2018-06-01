#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100010;
ll a[N];
ll ans[N], k = 0;
bool vis[N];
void init() {
	for(int i = 2; i < N; i ++) {
		if(!vis[i]) {
			ans[k++] = i;
			for(int j = i; j < N; j += i) vis[j] = true;
		}
	}
}
int main() {
	int t, n;
	init();
	cin >> t;
	while(t--) {
		cin >> n;
		ll sum = 0;
		for(int i = 1; i <= n; i ++) {
			cin >> a[i];
			sum += a[i];
		}
		ll cnt = sum / n, MIN = n;
		for(int i = 0;; i ++) {
			if(ans[i] > cnt) break;
			if(sum % ans[i] != 0) continue;
			int tmp = 0;
			for(int j = 1; j <= n; j ++) {
				if(a[j] % ans[i]) tmp ++;
			}
			if(MIN > n - tmp) MIN = n - tmp;
		}
		MIN = n - MIN;
		printf("%d\n",MIN/2+((MIN&1)?1:0));
	}
	return 0;
}