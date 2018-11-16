#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
int a[N];
int n, q, len, x;

int check() {
	int ans = 1;
	for(int i = 1; i <= len; i ++) ans *= 10;
	for(int i = 1; i <= n; i ++) {
		if(a[i]-x == a[i]/ans*ans) return a[i];
	}
	return -1;
}
int main() {
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a+1,a+1+n);
	while(q--) {
		cin >> len >> x;
		cout << check() << endl;
	}
	return 0;
}