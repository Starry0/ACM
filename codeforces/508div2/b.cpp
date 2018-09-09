#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;

int main() {
	int n; cin >> n;
	int s1 = 0, s2 = 0;
	for(int i = 1; i <= n; i += 2) s1 += i;
	for(int i = 2; i <= n; i += 2) s2 += i;
	if(__gcd(s1, s2) == 1) printf("No\n");
	else {
		printf("Yes\n");
		printf("%d",(n+1)/2);
		for(int i = 1; i <= n; i += 2) printf(" %d",i);printf("\n");
		printf("%d",n/2);
		for(int i = 2; i <= n; i += 2) printf(" %d",i);printf("\n");
	}
	return 0;	
}