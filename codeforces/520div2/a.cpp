#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1010], n, b[1010];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 2; i <= n; i ++) {
		if(a[i] == a[i-1]+1) b[i] = 1;
	}
	int ans = 0, cnt = 0;
	if(a[1] == 1) cnt = 1;
	for(int i = 2; i <= n; i ++) {
		if(b[i] == 1) cnt++;
		else{
			if(cnt >= 2) ans = max(ans, cnt-1);
			cnt = 0;
		}
	}
	if(cnt > 0) {
		if(a[n] == 1000) ans = max(ans, cnt);
		else ans = max(ans, cnt-1);
	}
	cout << ans << endl;
	return 0;
}