/*#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 3600*2;
int dp[N];
int a[20];
int main() {
	int T, n, t, x;
	scanf("%d", &T);
	while(T--) {
		memset(dp, INF, sizeof(dp));
		scanf("%d%d", &n, &t);
		dp[0] = 0;
		for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
		sort(a, a+n);
		for(int i = n-1; i >= 0; i --) {
			if(a[i] > 0) {
				for(int j = a[i]; j <= 3600; j ++) {
					dp[j] = min(dp[j-a[i]]+1, dp[j]);
				}
				for(int j = 3600-a[i]; j < 3600; j ++) {
					dp[3600] = min(dp[j]+1, dp[3600]);
				}
			} else if(a[i] < 0) {
				for(int j = N-1+a[i]; j >= 0; j --) {
					dp[j] = min(dp[j-a[i]]+1, dp[j]);
				}
			}
		}
		for(int i = 0; i < 1000; i ++) {
			printf("%d %d\n",i,dp[i] );
		}
		if(dp[t] != INF) {
			cout << dp[t] << ' ' << 0 << endl;
		} else {
			for(int i = t; i <= 3600; i ++) {
				if(dp[i] != INF) {
					cout << dp[i] << ' ' << i-t << endl;
					break;
				}
			}
		}
	}
	return 0;
}*/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int T, n, t;
int a[20], dp[4000];
typedef pair<int,int> P;
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &t);
		for(int i = 0; i < n; i ++) cin >> a[i];
		memset(dp, INF, sizeof(dp));
		queue<P> que;
		que.push(P(0,0));
		dp[0] = 0;
		int MIN = 1e5, Time = 1e5;
		while(que.size()) {
			P p = que.front(); que.pop();
			if(p.second >= t) {
				if(p.second < Time) {
					Time = p.second;
					MIN = p.first;
				} else if(p.second == Time) {
					MIN = min(MIN, p.first );
				}
			}
			for(int i = 0; i < n; i ++) {
				int tt = p.second + a[i];
				if(tt < 0) tt = 0;
				if(tt > 3600) tt = 3600;
				if(dp[tt] > p.first+1) {
					dp[tt] = p.first + 1;
					que.push(P(p.first+1,tt));
				}
			}
		}
		cout << MIN << ' ' << Time -t<< endl;
	}
	return 0;
}