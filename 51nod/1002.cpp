#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 550;
int a[N][N], dp[N][N];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= i; j ++) {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = n; i >= 1; i --) {
        for(int j = 1; j <= i; j ++)
            dp[i][j] = max(a[i][j] + dp[i+1][j], a[i][j] + dp[i+1][j+1]);
    }
    printf("%d\n",dp[1][1]);
    return 0;
}
