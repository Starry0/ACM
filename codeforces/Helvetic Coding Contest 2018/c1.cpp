#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n, p;
int a[N];
int main() {
	cin >> n >> p;
	int sum = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[i] %= p;
		a[i] += a[i-1];
	}
	for(int i = 1; i < n; i ++) {
		sum = max(sum,a[i]%p+(a[n]-a[i])%p);
	}
	cout << sum << endl;
	return 0;
}