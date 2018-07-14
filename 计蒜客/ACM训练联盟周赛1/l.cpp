#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 66;
int a[N][N], b[N][N];
int n, m;
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) cin >> a[i][j];
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) cin >> b[i][j];
	}
	
	return 0;
}