#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
ll n, m;
ll x[N], y[N];
ll a[N][N];
int main() {
	cin >> n >> m;
	ll ansx = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> x[i];
		ansx ^= x[i];
	}
	ll ansy = 0;
	for(int i = 1; i <= m; i ++) cin >> y[i], ansy ^= y[i];
	if(ansy == ansx) printf("YES\n");
	else return 0*printf("NO\n");
	ansx ^= x[1];
	ansx ^= y[1];
	a[1][1] = ansx;
	for(int i = 2; i <= m; i ++) a[1][i] = y[i];
	for(int i = 2; i <= n; i ++) a[i][1] = x[i];
	for(int i = 1; i <= n; i ++) {
		for(int j = 1 ; j <= m; j ++) {
			printf("%d ",a[i][j]);
		}printf("\n");
	}
	return 0;
}