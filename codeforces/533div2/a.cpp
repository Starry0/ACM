#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N], n;
int abs(int x) {
	return x>0?x:-x;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int MIN = N, t = 0;
	for(int i = 1; i <= 100; i ++) {
		int ans = 0;
		for(int j = 1; j <= n; j ++) {
			ans += min(abs(a[j]-i),min(abs(a[j]-i+1),abs(a[j]-i-1)));
		}
		if(ans < MIN) {
			MIN = ans;
			t = i;
		}
	}
	printf("%d %d\n",t,MIN);
	return 0;
}