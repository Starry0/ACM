#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n, k;
	cin >> n >> k;
	bool flag = true;
	for(ll i = 1; i <= k; i ++) {
		if(n%i != i-1) {
			flag = false;
			break;
		}
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}