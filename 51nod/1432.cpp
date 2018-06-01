#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e4+10;
int a[N];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a,a+n);
	int l = 0, r = n-1;
	int ans = 0;
	while(l <= r) {
		if(l == r) {
			ans++;
			break;
		}
		if(a[l]+a[r] <= m) {
			l++;r--;
		} else r--;
		ans++;
	}
	cout << ans << endl;
	return 0;
}