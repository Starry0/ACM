#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int c[N], a[N], fa[N];
int vis[N];
int main() {
	int t, n;
	cin >> n;
	for(int i = 1; i <= n; i ++) fa[i] = i;
	for(int i = 1; i <= n; i ++) cin >> c[i];
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		if(!vis[i]) {
			int tmp = i;
			while(true) {
				if(vis[tmp]) break;
				vis[tmp] = 2;
				tmp = a[tmp];
			}
			if(vis[tmp] == 2) {
				int cnt = c[tmp];
				int tmp1 = a[tmp];
				while(tmp1 != tmp) {
					cnt = min(c[tmp1], cnt);
					tmp1 = a[tmp1];
				}
				ans += cnt;
			}
			tmp = i;
			while(vis[tmp] != 1) {
				vis[tmp] = 1;
				tmp = a[tmp];

			}
		}
	}
	cout << ans << endl;
	return 0;

}