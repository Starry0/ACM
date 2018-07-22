#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000;
ll a[N], x, y, flag;

void dfs(ll x, int ans) {
	a[ans] = x;
	if(flag || x > y) {
		return ;
	}
	if(x == y) {
		flag = 1;
		printf("YES\n");
		for(int i = 0; i <= ans; i ++) printf("%lld%c",a[i]," \n"[i==ans]);
		return;
	}
	dfs(x*2, ans+1);
	dfs(x*10+1,ans+1);
}

int main() {
	cin >> x >> y;
	dfs(x,0);
	if(!flag) printf("NO\n");
	return 0;
}