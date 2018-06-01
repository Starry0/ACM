#include <bits/stdc++.h>
using namespace std;
int vis[10];
bool ok(int a, int b, int c) {
	memset(vis, false, sizeof(vis));
	while(a > 0) {
		vis[a%10]++;
		a /= 10;
	}
	while(b > 0) {
		vis[b%10]++;
		b /= 10;
	}
	while(c > 0) {
		vis[c%10]++;
		c /= 10;
	}
	for(int i = 1; i < 10; i ++) {
		if(vis[i] != 1) return false;
	}
	if(!vis[0])return true;
	else return false;
}
int main() {
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= 1000; i ++) {
		for(int j = 2; j < 1000; j ++) {
			int b = i*j;
			int s = n-j;
			if(s > 0) {
				if(ok(i,b,s)) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}