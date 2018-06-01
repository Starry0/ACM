#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[110];
int main() {
	int n, x, y;
	cin >> n >> x;
	for(int i = 0; i < n; i ++) {
		cin >> y;
		a[y]++;
	}
	int ans = 0;
	for(int i = 0; i < x; i ++) {
		if(a[i] == 0) ans++;
	}
	printf("%d\n", ans+(a[x]?1:0));
	return 0;
}