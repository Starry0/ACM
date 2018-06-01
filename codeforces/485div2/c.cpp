#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 3010;
int n, s[N], c[N];
int dp[N][3];
int main() {
    cin >> n;
    memset(dp, INF, sizeof(dp));
    for(int i = 0; i < n; i ++) cin >> s[i];
    for(int i = 0; i < n; i ++) cin >> c[i], dp[i][0] = c[i];
    for(int i = 1; i < 3; i ++) {
        for(int j = 0; j < n; j ++) {
            for(int k = 0; k < j; k ++) {
                if(s[j] > s[k]) {
                    dp[j][i] = min(dp[j][i],dp[k][i-1] + c[j]);
                }
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < n; i ++) ans = min(dp[i][2], ans);
    printf("%d\n",ans==INF?-1:ans);
    return 0;
}
