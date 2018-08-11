#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
bool vis[N];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) cin >> a[i], vis[a[i]] = 1;
	int l = 1, r = 1;
	while(l <= n && r <= m) {
		while(vis[l]) l++;
		if(a[r] > l) printf("%d\n",l++);
		else printf("%d\n",a[r++]);
	}
	while(l <= n) {
		if(!vis[l]) printf("%d\n",l);
		l++;
	}
	while(r <= m) printf("%d\n",a[r++]);
	return 0;
}