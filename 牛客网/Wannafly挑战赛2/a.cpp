#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
#define ll long long
int a[N];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	ll sum = 0;
	for(int i = 1; i <= n; i ++) {
		sum += 1LL*i*a[i];
	}
	cout << sum - a[n]<< endl;
	return 0;
}