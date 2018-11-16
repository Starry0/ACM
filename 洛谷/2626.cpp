#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = (1LL<<31);
ll f[50], x, a[100];
int main() {
	f[1] = f[2] = 1;
	for(int i = 3; i <= 48; i ++) f[i] = (f[i-1] + f[i-2])%mod;
	int n, ans = 0, y = 2;
	cin >> n;
	printf("%lld=",f[n]);
	if(n <= 2) return 0*printf("1\n");
	x = f[n];
	while(x > 1) {
		while(x > 0 && x%y == 0) {
			a[ans++] = y;
			x /= y;
		}
		y++;
	}
	cout << a[0];
	for(int i = 1; i < ans; i ++) printf("*%lld",a[i]);
	printf("\n");
	return 0;
}