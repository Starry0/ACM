#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e5+10;
int a[N], n, q, ans[N];
int dp[N][2];

int main() {
   cin >> n >> q;
   for(int i = 0; i < N; i ++) dp[i][0] = INF, dp[i][1] = 0;
   for(int i = 1; i <= n; i ++) {
      scanf("%d", &a[i]);
      dp[a[i]][0] = min(dp[a[i]][0],i);
      dp[a[i]][1] = max(dp[a[i]][1],i);
   }
   for(int i = q; i >= 1; i --) {
      int l = dp[i][0], r = dp[i][1];
      if(r == 0) continue;
      for(int j=l,k=r; j <= k; j++,k--) {
         if(ans[j] && ans[k]) break;
         if(ans[j] == 0) ans[j] = i;
         if(ans[k] == 0) ans[k] = i;
         if(a[j] == i) ans[j] = 1;
         else if(a[j] < i) return 0*printf("NO\n");
         if(a[k] == i) ans[k] = 1;
         else if(a[k] < i) return 0*printf("NO\n");
      }
   }
   if(dp[q][1] == 0) {
      if(dp[0][1] == 0) return 0*printf("NO\n");
      else {
         a[dp[0][0]] = q;
         for(int i = 1; i <= n; i ++) if(!a[i]) a[i] = a[i-1];
         printf("YES\n");
         for(int i = 1; i <= n; i ++)
            printf("%d%c",a[i]," \n"[i==n]);
      }
   } else {
      int cnt = 0;
      for(int i = 1; i <= n; i ++) {
         if(a[i]) {
            cnt = i;break;
         }
      }
      for(int i = cnt-1, j = cnt+1; i >= 1 || j <= n; i--,j++) {
         if(i >= 1 && !a[i]) a[i] = a[i-1];
         if(j <= n && !a[j]) a[j] = a[j-1];
      }
      printf("YES\n");
      for(int i = 1; i <= n; i ++)
         printf("%d%c",a[i]," \n"[i==n]);
   }
   return 0;
}