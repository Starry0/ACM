#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int a[N], n, x;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		a[x]++;
	}
	ll x = 1, y = 1;
	for(int i = 10000; i >= 1; i --) {
		if(a[i]) {
			x = i;
			break;
		}
	}
	for(int i = 1; i <= x; i ++) {
		if(x%i == 0) {
			a[i]--;
		}
	}
	for(int i = 10000; i >= 1; i --) {
		if(a[i]) {
			y = i;break;
		}
	}
	printf("%lld %lld\n",x,y );
	return 0;
}