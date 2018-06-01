// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <algorithm>
// #include <set>
// #define ll long long
// using namespace std;
// int sum[40]= { 	0, 0, 1, 3, 8, 20, 47, 107, 238, 520, 1121, 2391, 5056, 10616,
//     22159, 46023, 95182, 196132, 402873, 825259, 1686408, 3438828, 6999071,
//     14221459, 28853662, 58462800, 118315137, 239186031, 483072832, 974791728,
//     1965486047};
// int fun(int x, int n){
//     int ans = 0;
//     if(n == 0) return 1;
//     if(n&1){
//         for(int i = n; i >= (n+1)/2; i --){
//             int r = i, l = n-i;
//             int x = sum[r-1], y;
//             if(l <= 1) y = 1;
//             else y = sum[l-1];
//             ans += x*y;
//         }
//         return ans*2;
//     }else {
//         int x,y;
//         for(int i = n; i >= n/2; i --){
//             int r = i, l = n-i;
//             x = sum[r-1], y;
//             if(y <= 1) y = 1;
//             else y = sum[l-1];
//             ans += x*y;
//         }
//         return ans*2-x*y;
//     }
// }
// int main() {
//     int n;
//     /*sum[0] = 1;
//     for(int i = 1; i <= 30; i ++)
//         sum[i] = sum[i-1]*2;*/
//     std::ios::sync_with_stdio(false);
//     while(scanf("%d",&n)&&n) {
//         cout << sum[n-1] << endl;
//     }
//     return 0;
// }


#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
ll dp[33][4];
int main() {
    dp[1][0] = dp[1][1] = 1;
    dp[1][2] = dp[1][3] = 0;
    for(int i = 2; i < 33; i ++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][1];
        dp[i][3] = dp[i-1][3]*2 + dp[i-1][2];
    }
    int n;
    while(scanf("%d",&n)&&n) {
        cout << dp[n][3] << endl;
    }
    return 0;
}
