#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define ll long long
using namespace std;
const int N = 110;
ll a[40] = {0, 1, 8, 49, 288, 1681, 9800, 57121, 332928, 1940449, 11309768, 65918161, 384199200, 2239277041, 13051463048, 76069501249, 443365544448, 2584123765441, 15061377048200, 87784138523761, 511643454094368, 2982076586042449, 17380816062160328};

int main() {
	ll t, x;
	cin >> t;
	for(ll i = 1; i <= t; i ++) {
		cin >> x;
		for(int j = 1; j < 40; j ++) {
			if(a[j] >= x) {
				printf("Case #%lld: %lld\n",i,a[j]);
				break;
			}
		}
	}
	return 0;
}