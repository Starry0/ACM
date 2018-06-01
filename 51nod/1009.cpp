#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
int dp[12][12];
int main() {
    int ans = 1, n;
    for(int i = 1; i < 10;i ++) {
        dp[i][0] = dp[i-1][9]+1;
        for(int j = 1; j < 10; j ++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][9];
            if(j == 1) dp[i][j] += ans -1;
        }
        ans *= 10;
    }
    cin >> n;
    int m = n, cnt = 0;
    while(m) {
        cnt++;
        m /= 10;
    }
    m = 1, ans = 0;
    for(int i = 1; i < cnt; i ++) m *= 10;
    while(cnt) {
        int x = n/m;
        if(x) {
            ans += dp[cnt][x-1];
            if(x == 1) ans += (n-x*m);
        }
        cnt--;
        n -= m*x;
        m/=10;
    }
    cout << ans << endl;
    return 0;
}
