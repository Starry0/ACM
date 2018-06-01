// #include <iostream>
// #include <string.h>
// #include <stdio.h>
// #include <vector>
// #define INF 1000000000000000L
// #define ll long long
// using namespace std;
// const int N = 100010;
// const int M = 1010;
// ll dp[M][11];
// ll a[N], b[N], k[M], p[M];
// void init() {
//     for(int i = 0; i < M; i ++) {
//         for(int j = 0; j < 11; j ++) dp[i][j] = INF;
//     }
//     for(int i = 0; i < 11; i ++) dp[0][i] = 0;
// }
// int main() {
//     int n, m;
//     ios::sync_with_stdio(false);
//     while(cin>>n>>m) {
//         ll ans1 = 0, ans2 = 0;
//         for(int i = 1; i <= n; i ++) {
//             cin>>a[i]>>b[i];
//             // scanf("%lld %lld", &a[i], &b[i]);
//             ans1 = max(ans1, b[i]);
//         }
//         for(int i = 1; i <= m; i ++) {
//             // scanf("%lld %lld", &k[i], &p[i]);
//             cin>>k[i]>>p[i];
//             ans2 = max(ans2, p[i]);
//         }
//         if(ans2 <= ans1) {
//             printf("-1\n");
//             continue;
//         }
//         init();
//         for(int i = 1; i <= m; i ++) {
//             for(int j = 1; j < M; j ++) {
//                 for(int l = 0; l < 11; l ++) {
//                     if(p[i] <= l) continue;
//                     ll ans = 1LL*(p[i] - l);
//                     if(ans >= j) {
//                         for(int u = 0; u < j; u ++) {
//                             dp[j][l] = min(dp[j][l], dp[u][l] + k[i]);
//                         }
//                     }else {
//                         for(int u = j-ans; u < j; u ++) {
//                             dp[j][l] = min(dp[j][l], dp[u][l] + k[i]);
//                         }
//                     }
//                     // dp[j][l] = min(dp[j][l], dp[0][l] + k[i]);
//                     // else dp[j][l] = min(dp[j][l], dp[j-ans][l]+k[i]);
//                 }
//             }
//         }
//         ll cnt = 0;
//         for(int i = 1; i <= n; i ++) {
//             if(a[i] <= 0) continue;
//             cnt += dp[a[i]][b[i]];
//         }
//         cout << cnt << endl;
//     }
//     return 0;
// }




//
// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <algorithm>
// #define ll long long
// using namespace std;
// const int N = 100010;
// const int M = 1010;
// const ll INF = 100000000000000L;
// ll a[N], b[N], k[M], p[M];
// int n, m;
// ll dp[M][11];
// ll fun(ll x, ll y) {
//     ll ans = 0;
//     ll x1 = INF, y1 = 1;
//     int pos;
//     for(int i = 1; i <= m; i ++) {
//         if(p[i] <= y)continue;
//         if(x1*(p[i]-y) > y1*k[i]) {
//             pos = i;
//             x1 = k[i]; y1 = (p[i]-y);
//         }
//     }
//     ans += (x/(p[pos]-y))*k[pos];
//     x = x - (x/(p[pos]-y))*(p[pos]-y);
//     if(x == 0) return ans;
//     else {
//         x1 = INF;
//         for(int i = 1; i <= m; i ++) {
//             if(p[i] <= y) continue;
//             if((p[i]-y) >= x){
//                 x1 = min(x1,k[i]);
//             }
//         }
//         return ans+x1;
//     }
//
// }
// int main() {
//     ios::sync_with_stdio(false);
//     while(cin>>n>>m) {
//         ll ans1 = 0, ans2 = 0;
//         for(int i = 1; i <= n; i ++) {
//             cin >> a[i] >> b[i];
//             ans1 = max(ans1, b[i]);
//         }
//         for(int i = 1; i <= m; i ++) {
//             cin >> k[i] >> p[i];
//             ans2 = max(ans2, p[i]);
//         }
//         if(ans2 <= ans1 && ans1 != 0) {
//             printf("-1\n");
//             continue;
//         }
//         for(int i = 1; i < M; i ++) {
//             for(int j = 0; j <= ans1; j ++) {
//                 dp[i][j] = fun(i,j);
//                 // printf("%d   %lld\n", j,dp[i][j]);
//             }
//         }
//         ll ans = 0;
//         for(int i = 1; i <= n; i ++) {
//             ans += dp[a[i]][b[i]];
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }




#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const int N = 100010;
const int M = 1010;
ll a[N], b[N], p[M], k[M];
ll dp[M][12];
int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        ll ans1 = 0, ans2 = 0, ans3 = 0;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i] >> b[i];
            ans1 = max(ans1, a[i]);
            ans2 = max(ans2, b[i]);
        }
        for(int i = 1; i <= m; i ++) {
            cin >> k[i] >> p[i];
            ans3 = max(ans3, p[i]);
        }
        if(ans3 <= ans2) {
            printf("-1\n");
            continue;
        }
        for(int i = 0; i < M; i ++) {
            for(int j = 0; j < 12; j ++) dp[i][j] = 100000000000L;
        }
        for(int i = 0; i < 12; i ++) dp[0][i] = 0;
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= ans1; j ++) {
                for(int l = 0; l < 12; l ++) {
                    if(p[i] <= l) continue;
                    int ans = p[i]-l;
                    if(ans >= j) dp[j][l] = min(dp[j][l], dp[0][l]+k[i]);
                    else dp[j][l] = min(dp[j][l], dp[j-ans][l]+k[i]);
                }
            }
        }
        ll sum = 0;
        for(int i = 1; i <= n; i ++) {
            if(a[i] <= 0) continue;
            sum += dp[a[i]][b[i]];
        }
        printf("%lld\n",sum);
    }
    return 0;
}
