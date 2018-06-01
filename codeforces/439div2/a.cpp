#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int x[N], y[N];
map<int, int> mp;
int main() {
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++) scanf("%d", &x[i]),mp[x[i]]++;
	for(int i = 1; i <= n; i ++) scanf("%d", &y[i]),mp[y[i]]++;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(mp.count(x[i]^y[j])) ans++;
		}
	}
	if(ans%2) printf("Koyomi\n");
	else printf("Karen\n");
	return 0;
}