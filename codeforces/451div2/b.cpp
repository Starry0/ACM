#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll a, b, n, x = 0;
	cin >> n >> a >> b;
	for(; x*a <= n && (n-x*a)%b != 0; x++);
	if(x*a <= n) {
		printf("YES\n");
		cout << x << " " << (n-x*a)/b << endl;
	}
	else printf("NO\n");
	return 0;
}