#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e5+10;
int a[N], n, q, ans[N];
int dp[2][N];
int main() {
    scanf("%d%d",&n, &q);
    memset(dp[0], INF, sizeof(dp[0]));
    memset(dp[1], 0, sizeof(dp[1]));
    for(int i = 1; i <= n; i ++) {
        scanf("%d",&a[i]);
        dp[0][a[i]] = min(dp[0][a[i]], i);
        dp[1][a[i]] = max(dp[1][a[i]], i);
    }
    for(int i = q; i >= 1; i --) {
		int l = dp[0][i], r = dp[1][i];
        if(r == 0) continue;
        for(int j = l,k = r;j <= k; j ++, k --) {
            if(ans[j] && ans[k]) break;
            if(a[j] == 0) a[j] = i;
            if(a[k] == 0) a[k] = i;
            if(a[j] == i) ans[j] = 1;
            else if(a[j] < i) return 0*printf("NO\n");
            if(a[k] == i) ans[k] = 1;
            else if(a[k] < i) return 0*printf("NO\n");
        }
    }
    if(dp[1][q] == 0) {
        if(dp[1][0] == 0) return 0*printf("NO\n");
        else {
			a[dp[0][0]]=q;
            for(int i = 1;i <= n; i ++)  if(a[i]==0) a[i]=a[i-1];
            printf("YES\n");
            for(int i = 1;i <= n; i ++) printf("%d%c",a[i]," \n"[i==n]);
        }
    } else {
        int cnt = 0;
        for(int i = 1; i <= n; i ++)
            if(a[i]){
                cnt = i;
                break;
            }
        for(int i = cnt-1, j = cnt+1; i >= 1 || j <= n; i --, j ++) {
            if(i >= 1 && a[i] == 0) a[i]=a[i+1];
            if(j <= n && a[j] == 0) a[j]=a[j-1];
        }
		printf("YES\n");
        for(int i = 1;i <= n; i ++) printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}
