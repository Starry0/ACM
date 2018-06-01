#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
int p[N], l, n, c, t, v, v1, v2;
double dp[N];
int main() {
    while(cin >> l) {
        cin >> n >> c >> t;
        cin >> v >> v1 >> v2;
        for(int i = 1; i <= n; i ++) cin >> p[i];
        dp[n+1] = l;
        double ans = c;
        for(int i = 1; i <= n+1; i ++) {
            dp[i] = INF;
            
        }
    }
    return 0;
}
