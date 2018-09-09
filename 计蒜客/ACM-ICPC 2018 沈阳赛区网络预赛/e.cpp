#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
char s[N];
bool ok(int x) {
	for(int i = 2; i <= sqrt(x); i ++) {
		if(x%i==0) return false;
	}
	return true;
}
int main() {
	int t;
	for(int i = 10; i <= 100; i ++) {
		if(ok(i)) printf("%d ",i);
	}
	scanf("%d", &t);
	while(t--) {

	}
	return 0;
}