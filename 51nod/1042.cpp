#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#define ll long long
using namespace std;

ll dp[20];

void init() {
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= 18; i ++) {
		dp[i] = dp[i-1]*10 + pow(10,i-1);
	}
}
ll count(ll r, int x) {
	ll sum = 0, len = 0, cnt = 1, tail = 0, rr = r;
	while(r) {
		int tmp = r%10;
		r /= 10;
		len ++;
		if(tmp > x) {
			sum += dp[len-1]*tmp + cnt;
		} else if(tmp == x) {
			sum += dp[len-1]*tmp + tail + 1;
		} else {
			sum += dp[len-1]*tmp;
		}
		tail = tail + tmp*cnt;
		cnt *= 10;
	}
	if(!x) { //是0的话就删除前缀为0的
		ll ans = 1;
		while(rr) {
			sum -= ans;
			ans *= 10;
			rr /= 10;
		}
	}
	return sum;
}
int main() {
	init();
	ll a, b;
	cin >> a >> b;
	for(int i = 0; i < 10; i ++) {
		cout << count(b,i) - count(a-1,i) << endl;		
	}
	return 0;
}