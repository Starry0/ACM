#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n, k;
	cin >> n >> k;
	if(k == 1) printf("1\n");
	else if(k == 2) printf("%lld\n",1+n*(n-1)/2);
	else if(k == 3) printf("%lld\n",1+n*(n-1)/2+n*(n-1)*(n-2)/3);
	else if(k == 4) printf("%lld\n",1+n*(n-1)/2+n*(n-1)*(n-2)/3+n*(n-1)*(n-2)*(n-3)*3/8);
	return 0;
}