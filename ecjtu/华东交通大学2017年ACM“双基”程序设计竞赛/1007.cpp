#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
int a[N], vis[N];
int k, n, x, ans;
bool ok(int x) {
	int sum = x*k;
	for(int i = 0; i < ans; i ++) {
		
	}
}
int main() {
	while(cin >> k >> n){
		for(int i = 0; i < n; i ++) cin >> x, vis[x] ++;
		ans = 0;
		for(int i = 0; i <= 1000; i ++) {
			if(vis[i]) a[ans++] = i;
		}
		int l = 1, r = 1e6;
		while(l <= r) {
			int m = (l+r) >> 1;
			if(ok(m)) r = m-1;
			else l = m+1;
		}
	}
	return 0;
}