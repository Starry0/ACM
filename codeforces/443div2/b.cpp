#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 550;
int a[N];
int main() {
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i ++) cin >> a[i];
	if(k >= n) printf("%d\n",n);
	else {
		for(int i = 0; i < n; i ++) {
			int ans = 0;
			if(i != 0 && a[i] > a[i-1]) ans++;
			for(int j = 1; j <= n; j ++) {
				if(a[i] > a[(i+j)%n]) ans ++;
				if(ans >= k) return 0*printf("%d\n",a[i]);
				if(a[i] <= a[(i+j)%n]) break;
			}
		}
	}
	return 0;
}


bool isPrime(int x) {
	if(x < 2) return false;
	for(int i = 2; i <= sqrt(x); i ++) {
		if(x % i == 0) return false;
	}
	return true;
}