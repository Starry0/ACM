#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#define ll long long
using namespace std;
ll solve(ll y) {
	ll n = y / 4, ans = y % 4, x;
	if(ans == 0) {
		x = 2*n*n;
	}else if(ans == 1) {
		x = 2*n*n+n-1;
	}else if(ans == 2) {
		x = 2*n*n+2*n;
	}else if(ans == 3) {
		x = 2*n*n+3*n;
	}
	return x;
}
int main() {
	ll t, x;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &x);
		for(ll i = 4; ; i ++) {
			if(solve(i) >= x) {
				printf("%lld\n",i);
				break;
			}
		}
	}
	return 0;
}