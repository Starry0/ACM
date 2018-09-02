#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
int a[11],val[] = {1,5,10,20,50,100,200,500,1000,2000}, ans;
void dfs(int i, int s, int cnt) {
	if(s == 0) {
		ans = min(ans, cnt);
		return;
	}
	if(i < 0) return;
	int c = min(a[i], s/val[i]);
	dfs(i-1,s-c*val[i], cnt + c);
	if(c > 0) {
		c--;
		dfs(i-1,s-c*val[i], cnt + c);
	}
}
int main() {
	int t, p;
	scanf("%d", &t);
	while(t--) {
		cin >> p;
		int sum = 0, q = 0;
		ans = INF;
		for(int i = 0; i < 10; i ++) {
			cin >> a[i];
			q += a[i]*val[i];
			sum += a[i];
		}
		int s = q-p;
		if(s < 0) {
			printf("-1\n");
			continue;
		}
		dfs(9, s, 0);
		if(ans == INF) printf("-1\n");
		else printf("%d\n",sum-ans);
	}
	return 0;
}