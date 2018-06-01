#include <bits/stdc++.h>
using namespace std;
int ans[15], n, a, b, MIN = 1000000;
bool check(){
	for(int i = 1; i <= n; i ++) {
		if(ans[i] >= 0) return false;
	}
	return true;
}
void dfs(int l, int depth) {
	if(l == n) {
		MIN = min(MIN, depth);
		return;
	}
	if(ans[l-1] < 0) dfs(l+1,depth);
	int x = 0, y;
	if(ans[l-1] >= 0) {
		x = ans[l-1]/b+1;
		ans[l-1] -= x*b;
		ans[l] -= x*a;
		ans[l+1] -= x*b;
		dfs(l+1,depth+x);
		ans[l-1] += x*b;
		ans[l] += x*a;
		ans[l+1] += x*b;
	}
	y = ans[l]/a+1;
	if(y > x && ans[l] >= 0) {
		for(int i  = x+1; i <= y; i ++) {
			ans[l-1] -= i*b;
			ans[l] -= i*a;
			ans[l+1] -= i*b;
			dfs(l+1,depth+i);
			ans[l-1] += i*b;
			ans[l] += i*a;
			ans[l+1] += i*b;
		}
	}
}
int main() {
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i ++) scanf("%d", &ans[i]);
	int cnt = ans[1] / b + 1;
	ans[1] -= cnt*b;
	ans[2] -= cnt*a;
	ans[3] -= cnt*b;
	if(ans[n] >= 0) {
		int tmp = ans[n]/b+1;
		cnt += tmp;
		ans[n] -= b*tmp;
		ans[n-1] -= a*tmp;
		ans[n-2] -= b*tmp;
	}
	dfs(2,0);
	printf("%d\n",MIN+cnt);
	return 0;
}