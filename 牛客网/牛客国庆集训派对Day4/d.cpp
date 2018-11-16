#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N], n;
int main() {
	ll sum = 0;
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i], sum += 1LL*a[i];
	if(n == 0) return 0*printf("0\n");
	sort(a,a+n);
	printf("%lld\n",sum+1LL*(n-2)*a[0]);
	return 0;
}