#include <bits/stdc++.h>
using namespace std;
const int mod = 20123;
const int N = 1e4+1;
const int M = 101;
int a[N][M], b[N];
bool vis[N][M];
int main() {
	int n, m, op, x;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		int ans = 0;
		for(int j = 0; j < m; j ++) {
			cin >> vis[i][j] >> a[i][j];
			ans += vis[i][j];
		}
		b[i] = ans;
	}
	int cnt = 0, id, h = 1;
	cin >> id;
	while(h <= n) {
		x = a[h][id];
		cnt = (cnt+x)%mod;
		x %= b[h];
		if(x == 0) x += b[h];
		int ans = 0;
		for(int i = 0; i < m; i ++) {
			if(vis[h][(id+i)%m]) ans++;
			if(ans == x) {
				id = (id+i)%m;
				break;
			}
		}
		h++;
	}
	cout << cnt << endl;
	return 0;
}