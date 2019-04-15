#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
struct Nod{
	int d, t;
}e[N];
int dp[N];
int T[N];
bool cmp(const Nod &a, const Nod &b) {
	return a.d < b.d;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n, m;
	cin >> t;
	for(int ca = 1; ca <= t; ca ++) {
		cin >> n >> m;
		for(int i = 1; i <= n; i ++) cin >> e[i].d;
		for(int i = 1; i <= n; i ++) cin >> e[i].t;
		sort(e+1,e+1+n,cmp);	
		// sort(T+1, T+1+n);
		//dp[0] = 0;
		int cnt  = 0;
		for(int i = 1; i <= n; i ++) {
			// printf("%d %d %d\n",m,e[i].d,e[i].t);
			if(m >= e[i].t) {
				cnt++;
				m -= e[i].t;
			} else break;
		}
	//	printf("\n");
		printf("Case %d: %d\n",ca,cnt);

	}
	return 0;
}