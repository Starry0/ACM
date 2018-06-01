#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
#define lowvit(x) x&(-x)
#define N 1010
#define M 110
using namespace std;
char str[N];
bool dp[N][N];
int dp1[N];
int main() {
    int t;
    cin>>t;
    while(t--) {
        memset(dp, 0, sizeof(dp));
        memset(str, 0, sizeof(str));
        memset(dp1, 0, sizeof(dp1));
        cin>>str+1;
        int len = strlen(str+1);
        for(int i = 1; i <= len; i ++) {
            dp[i][i] = 1;dp1[i] = INF;
            if(i+1 <= len && str[i] == str[i+1]) dp[i][i+1] = 1;
        }
        for(int i = 3; i <= len; i ++) {
            for(int j = 1; j <= len-i+1; j ++) {
                int r = j+i-1;
                if(dp[j+1][r-1] && str[j] == str[r]) dp[j][r] = 1;
            }
        }
        dp1[0] = 0;
        for(int i = 1; i <= len; i ++) {
            for(int j = 1; j <= len; j ++) {
                if(dp[j][i]) {
                    dp1[i] = min(dp1[i],dp1[j-1]+1);
                }
            }
        }
        cout << dp1[len] << endl;
    }
    return 0;
}

//
// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <algorithm>
// #include <string>
// #include <queue>
// #include <vector>
// #include <set>
// #include <map>
// #define ll long long
// #define INF 0x3f3f3f3f
// #define lowvit(x) x&(-x)
// #define N 1100
// #define M 110
// using namespace std;
// char str[N];
// bool isA(int l, int r) {
//     while(l <= r) {
//         if(str[l] != str[r]) return false;
//         l++;r--;
//     }
//     return true;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     int t;
//     cin>>t;
//     while(t--) {
//         cin>>str;
//         int len = strlen(str);
//         int ans = 0;
//         int l = 0;
//         while(l < len) {
//             for(int j = len-1; j >= l; j --) {
//                 if(isA(l,j)) {
//                     ans++;
//                     l = j +1;
//                 }
//             }
//         }
//         printf("%d\n",ans);
//         memset(str, 0, sizeof(str));
//     }
//     return 0;
// }
