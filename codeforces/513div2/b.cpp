#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int f(ll x) {
	int sum = 0;
	while(x) {
		sum += x%10;
		x /= 10;
	}
	return sum;
}

int main() {
	ll n, x = 1, m;
	cin >> n;
	m = n;
	while(m) {
		x *= 10;
		m /= 10;
	}
	x /= 10;
	ll a = 0, b = 0;
	while(a*10+9 < x) {
		a = a*10 + 9;
	}
	int MAX = 0;
	for(ll i = 0; i < 10; i ++) {
		ll b = n - i*x-a;
		// printf("%lld %lld\n",a+i*x,b );
		if(b < 0) break;
		MAX = max(MAX, f(a+i*x)+f(b));
	}
	printf("%d\n",MAX);
	return 0;
}