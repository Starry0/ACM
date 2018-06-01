#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 0x3f3f3f3f
#define ll long long
const int N = 1010;
using namespace std;
ll n;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	ll x = 1;
	for(int i = 1; i <= 33; i ++) {
		if(x == n) return 0*printf("yes\n");
		x *= 2;
		//printf("%lld\n",x);
	}
	printf("no\n");
	return 0;
}