#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll b[11];
int main() {
	ll k, p,i;
	cin >> k >> p;
	ll ans = 0;
	for(i = 1; i <= k ; i ++) {
		ll tmp = i, cnt = 0;
		while(tmp > 0) {
			b[cnt++] = tmp % 10;
			tmp /= 10;
		}
		ll xx = 1;
		for(int j = 0; j < cnt; j ++) {
			tmp = tmp*10 + b[j];
			xx *= 10;
		}
		cnt = i;
		ans += cnt*xx+tmp;
		//cout << tmp*xx+cnt << endl;
		ans %= p;
	}
	cout << (ans+p)%p  << endl;
	return 0;
}