#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 110;
const ll mod = 1000000007;
char str[N], str1[N];
int main() {
	ll n, ans = 1;
	cin >> n >> str >> str1;
	bool flag = false;
	for(ll i = 0; i < n; i ++) {
		if(i == 0) {
			if(str[i] == str1[i]) {
				ans = 3;
			} else {
				ans = 6;flag = true;i++;
			}
		}else {
			if(str[i] == str1[i]) {
				if(flag) {
					flag = false;
				}else {
					ans *= 2;
					ans %= mod;
				}
				flag = false;
			} else {
				if(flag) {
					ans *= 3;
					ans %= mod;
				}else {
					ans *= 2;
					ans %= mod;
				}
				flag = true;
				i++;
			}
		}
	}
	printf("%lld\n",ans%mod);
	return 0;
}
