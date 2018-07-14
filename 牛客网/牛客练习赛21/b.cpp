#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 510;
int a[N][N], dp[N][N];
int t, n, m;

int main() {
	scanf("%d", &t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) {
            scanf("%d",&a[i][j]);
        }
		dp[n][m] = a[n][m];
		for(int i = n; i > 0; i --) {
			for(int j = m; j > 0; j --) {
				int tmp;
				if(i==n&&j==m)continue;
				else if(i == n) tmp = dp[i][j+1];
				else if(j == m) tmp = dp[i+1][j];
				else tmp = max(dp[i][j+1],dp[i+1][j]);
				dp[i][j] = a[i][j] - tmp;
			}
		}
		printf("%d\n",dp[1][1]);
    }
    return 0;
}
