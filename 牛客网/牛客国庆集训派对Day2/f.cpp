#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int main() {
	int n, d;
	cin >> n >> d;
	if(n == 0 || n == 1 || d == 0) printf("0\n");
	else {
		ll ans1 = (1LL<<(n-1))-1;
		ll ans2 = max(n-1-d,0);
		printf("%lld\n",ans1-ans2);
	}
	return 0;
}