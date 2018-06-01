#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int dp[N], p[N], t[N];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i ++) cin >> p[i] >> t[i];
    int now = k;
    for(int i = n; i >= 1; i --) {
        if(p[now] != i) dp[i] = dp[i+1]+1;
        else{
            while(p[now] == i) {
                dp[i] = max(dp[i],dp[i+t[now]]);
                now --;
            }
        }
    }
    cout << dp[1] << endl;
    return 0;
}
//
// 15 6
// 1 2
// 1 6
// 4 11
// 8 5
// 8 1
// 11 5
