/*#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[50];
int t; 
ll n, ans;
bool ok() {
	for(int i = 0; i <= n-3; i ++) {
		// printf("%d %d %d\n",a[i],a[i+1],a[i+2]);
		if(a[i] == a[i+1] && a[i+1] == a[i+2]) return false;
		if(a[i] != a[i+1] && a[i+1] != a[i+2] && a[i] != a[i+2] && a[i+1] == 2) return false;
		if(a[i] == a[i+2] && a[i] == 2) return false;
	}
	return true;
}
void dfs(int x) {
	if(x == n) {
		if(ok()) {
			ans++;
		}
		return;
	}
	for(int i = 1; i <= 3; i ++) {
		a[x] = i;
		dfs(x+1);
	}
}
int main() {
	cin >> t;
	while(t--) {
		scanf("%lld", &n);
		ans = 0;
		dfs(0);
		printf("%lld\n",ans);
	}
	return 0;
}*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int dp[100][4], n;
int main() {
	dp[1][1] = dp[1][2] = dp[1][3] = 1;
	dp[2][1] = dp[2][2] = dp[2][3] = 3;
	for(int i = 3; i < 100; i ++) {
		dp[i][1] = dp[i-1][1]+dp[i-1][2]+dp[i-1][3] - dp[i-2][1]-dp[i-2][3];
		dp[i][2] = dp[i-1][1]+dp[i-1][2]+dp[i-1][3] - dp[i-2][2]*3;
		dp[i][3] = dp[i-1][1]+dp[i-1][2]+dp[i-1][3] - dp[i-2][1] - dp[i-2][3];
	}
	for(int i = 3; i <= 100; i ++) {
		printf("%d %d %d %d %d\n",i, dp[i][1],dp[i][2],dp[i][3],dp[i][1]+dp[i][2]+dp[i][3] );
	}
	int t; cin >> t;
	while(t--) {
		cin >> n;

	}
	return 0;
}

/*#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	for(int i = -50; i <= 50; i ++) {
		printf("%d\n",i);
		for(int j = -50; j <= 50; j ++) {
			for(int k = -50; k <= 50; k ++) {
				for(int l = -50; l <= 50; l ++) {
					for(int q = -50; q <= 50; q ++) {
						if(i*244+j*106+k*46+l == 560) {
							if(i*560+j*244+k*106+l*20+q == 1286)
							if(i*1286+j*560+k*244+l*106+q == 2956)
							if(i*2956+j*1286+k*560+l*244+q == 6794)
							printf("%d %d %d %d\n",i,j,k,l);
						}
					}
				}
			}
		}
	}
	return 0;
}*/