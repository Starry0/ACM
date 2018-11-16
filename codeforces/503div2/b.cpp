#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
int n, m;
int a[N];
bool vis[N];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) {
		int tmp = a[i];
		vis[i] = 1;
		while(!vis[tmp]) {
			vis[tmp] = 1;
			tmp = a[tmp];
		}
		printf("%d ",tmp);
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}