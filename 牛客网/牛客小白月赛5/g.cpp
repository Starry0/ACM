#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main() {
	ll n;
	while(scanf("%lld", &n) != EOF){
		cout << n/3*2+n%3 << endl;
	}
	return 0;
}