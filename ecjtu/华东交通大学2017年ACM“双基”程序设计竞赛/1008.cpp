#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
int a[N], pre[N], sum[N];
int main() {
	int T;
	cin>> T;
	while(T--) {
		int n;
		cin >> n;
		memset(sum, 0, sizeof(sum));
		memset(pre, 0, sizeof(pre));
		for(int i = 1; i <= n; i ++) cin >> a[i];
		for(int i = 1; i <= n; i ++) {
			sum[i] = max(sum[i-1], a[i]);
		}
		for(int i = n; i > 0; i --) {
			pre[i] = max(pre[i+1], a[i]);
		}
		int MAX = -1;
		for(int i = 2; i <= n; i ++){
			MAX = max(MAX, abs(pre[i]-sum[i-1]));
		}
		printf("%d\n",MAX);
	}
	return 0;
}