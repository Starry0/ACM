#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll a[N], MAX = -1;
int n, s, f, ans;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	cin >> s >> f;
	int tmp = f-s;
	for(int i = 1; i <= n; i ++) {
		if(i+tmp-1 <= n) {
			if(a[i+tmp-1]-a[i-1] > MAX) {
				MAX = a[i+tmp-1]-a[i-1];
				ans = s - i + 1;
				if(ans <= 0) ans += n;
			} else if(a[i+tmp-1]-a[i-1] == MAX) {
				int ans1 = s - i + 1;
				if(ans1 <= 0) ans1 += n;
				ans = min(ans, ans1);
			}

		} else{
			if(a[n]-a[i-1]+a[tmp-(n-i+1)] > MAX) {
				MAX = a[n]-a[i-1]+a[tmp-(n-i+1)];
				ans = s - i + 1;
				if(ans <= 0) ans += n;
			} else if(a[n]-a[i-1]+a[tmp-(n-i+1)] == MAX) {
				int ans1 = s - i + 1;
				if(ans1 <= 0) ans1 += n;
				ans = min(ans, ans1);
			}
		}
	}
	cout << ans << endl;
    return 0;
}
