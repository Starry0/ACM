#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[6] = {1, 4, 2, 8, 5, 7};
void init() {
	for(ll i = 1; i < 20; i ++) {
		ll tmp = 10;
		for(ll j = 1; j < i; j ++) {
			tmp *= 10;
		}
		tmp /= 7;
		printf("%lld %lld\n",i,(tmp+10)%10);
	}
}
int main() {
	//init();
	ll n, t;
	cin >> t;
	while(t--) {
		cin >> n;
		n--;
		n %= 6;
		cout << a[n] << endl;
	}
	return 0;
}