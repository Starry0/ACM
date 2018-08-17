#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
const ll MAX = 1e9+10;

int main() {
	
	ll n, a, b;
	while(scanf("%lld%lld", &a, &b) != EOF) {
		if(b <= 1) printf("0\n");
		else if(b <= 2) printf("1\n");
		else if(a == b || a==b-1) printf("2\n");
		else if(b > a+1) {
			if(a == 0) a = 1;
			printf("%lld\n",(b-a)/2+1);
		}
	}
	return 0;
}