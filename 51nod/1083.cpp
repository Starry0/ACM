#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 550;
int a[N][N], dp[N][N];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            dp[i][j] = a[i][j] + max(dp[i][j-1], dp[i-1][j]);
        }
    }
    printf("%d\n",dp[n][n]);
    return 0;
}
