#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[110], dp[10000];
int main() {
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i], sum += a[i];
    for(int i = 1; i <= n; i ++) {
        for(int j = sum/2; j >= a[i]; j --) {
            dp[j] = max(dp[j], dp[j-a[i]] + a[i]);
        }
    }
    int x = 2*(sum/2 - dp[sum/2]) + (sum&1?1:0);
    printf("%d\n",x);
    return 0;
}
