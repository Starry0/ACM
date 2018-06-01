#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
bool ispri(int x) {
	if(x < 2) return false;
	for(int i = 2; i <= sqrt(x); i ++) {
		if(x % i == 0) return false;
	}
	return true;
}
int main() {
	int t, k = 0;
	std::ios::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n == 1) printf("Case #%d: 1\n",++k);
		else if(ispri(n)) {
			int ans = 1;
			for(int i = 1;i <= n-1; i ++) {
				ans *= 2;
				ans %= n;
			}
			printf("Case #%d: %d\n",++k,ans%n);
		}else {
			printf("Case #%d: %d\n",++k,(n-1)*(n-1)%n);
		}
	}
	return 0;
}