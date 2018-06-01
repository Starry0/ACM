#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 50010;
ll a[N];
int main() {
	ll n, sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]), sum += a[i];
	ll MAX1 = 0, tmp = 0, tmp1 = 0, MIN = 1000000000;
	for(int i = 1; i <= n; i ++) {
		tmp = max(0LL, tmp) + a[i];
		tmp1 = min(0LL, tmp1) + a[i]; 
		MAX1 = max(MAX1, tmp);
		MIN = min(MIN, tmp1);
	}
	printf("%lld\n",max(MAX1, sum - MIN));
	return 0;
}