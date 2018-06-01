#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll a[55], b[55];
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < m; i ++) cin >> b[i];
	ll cnt, MAX = -1e18;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			if(MAX < a[i]*b[j]) {
				MAX = a[i]*b[j];
				cnt = i;
			}
		}
	}
	MAX = -1e18;
	for(int i = 0; i < n; i ++) {
		if(i == cnt)continue;
		for(int j = 0; j < m; j ++) {
			if(MAX < a[i]*b[j]) {
				MAX = a[i]*b[j];
			}
		}
	}
	cout << MAX << endl;
	return 0;
}