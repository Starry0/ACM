#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+10;
struct Nod{
	int t, d, p, id;
}a[N];
bool cmp(Nod a, Nod b) {
	return a.d < b.d;
}
int dp[N];
vector<int> vs[N];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d %d", &a[i].t,&a[i].d,&a[i].p);
		a[i].id = i;
	}
	sort(a+1, a+1+n, cmp);
	// for(int i = 1; i <= n; i ++) {
	// 	printf("%d %d %d %d\n",a[i].t,a[i].d,a[i].p,a[i].id );
	// }
	for(int i = 1; i <= n; i ++) {
		for(int j = a[i].d-1; j >= a[i].t; j --) {
			if(dp[j-a[i].t] + a[i].p > dp[j]) {
				dp[j] = dp[j-a[i].t] + a[i].p;
				vs[j].clear();
				for(int ll = 0; ll < vs[j-a[i].t].size(); ll ++) {
					vs[j].push_back(vs[j-a[i].t][ll]);
				}
				vs[j].push_back(a[i].id);
			}
		}
		// for(int j = 21; j <= 30; j ++)
		// printf("__%d ",dp[j]);
	}
	int ans = 0, MAX = 0;
	for(int i = 1; i <= 2000; i ++) {
		if(MAX < dp[i]) {
			MAX = dp[i];
			ans = i;
		}
	}
	printf("%d\n%d\n",MAX,vs[ans].size());
	for(int i = 0; i < vs[ans].size(); i ++) printf("%d%c",vs[ans][i] , i == vs[ans].size()-1?'\n':' ');
	return 0;
}