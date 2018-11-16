#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i ++) a[i] += a[i-1];
	for(int i = 1; i <= n; i ++) a[i] += a[i-1];
	cout << a[n] << endl;
	return 0;
}