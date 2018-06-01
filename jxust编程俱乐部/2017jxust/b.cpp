#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 0x3f3f3f3f
#define ll long long
const int N = 1010;
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	for(ll i = 1; i <= m; i ++) {
		printf("%lld ", n%i);
	}
	printf("\n");
	return 0;
}