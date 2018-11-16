#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n, a[N];
int main() {
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a,a+n);
	int tmp = n-2;
	int ans = 0;
	for(int i = n-1; i >= 0; i --) {
		while(a[tmp] >= a[i] && tmp >= 0) tmp--;
		if(tmp < 0) break;
		ans++;tmp--;

	}
	cout << ans << endl;
	return 0;
}

// 1 1 1 1 5 5