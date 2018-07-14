#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int a[N], n;
int main() {
	int t;
	cin >> t;
	while(t--) {
		ll a, b, c, d;
		cin >> a >>b >> c >> d;
		if(a< b || d < b || c < d) printf("No\n");
		else {
			printf("Yes\n");
		}
	}
	return 0;
}