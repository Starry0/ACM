#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[33], l, r, k;
ll solve(ll lv, ll v) {
	if(lv == k) return v;
	return solve(lv+1,v)-solve(lv+1,v/a[lv]);
}
int main() {
	cin >> l >> r >> k;
	for(int i = 0; i < k; i ++) cin >> a[i];
	cout << solve(0, r) - solve(0,l-1) << endl;
	return 0;
}