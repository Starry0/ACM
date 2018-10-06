#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2010;
ll a[N], b[N], n, m, x;
int c[N*N];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i], a[i] += a[i-1];
	for(int j = 1; j <= m; j ++) cin >> b[j], b[j] += b[j-1];
	cin >> x;
	for(int i = 1; i <= m; i ++) {
		for(int j = i; j <= m; j ++) {
			ll tmp = b[j]-b[i-1];
			c[tmp] = max(c[tmp], j-i+1); 
		}
	}
	for(int i = 1; i <= b[m]; i ++) {
		c[i] = max(c[i], c[i-1]);
	}
	int MAX = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = i; j <= n; j ++) {
			ll tmp = x / (a[j]-a[i-1]);
			if(tmp <= 0) continue;
			if(tmp > b[m]) tmp = b[m];
			MAX = max(MAX, c[tmp]*(j-i+1));
		}
	}
	cout << MAX << endl;
	return 0;
}