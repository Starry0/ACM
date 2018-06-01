#include <bits/stdc++.h>
using namespace std;
const int MAX = 5010;
char str[MAX];
int dp[MAX][MAX], ans[MAX], n;
int getK(int l, int r) {
    if(dp[l][r] == 0) return 0;
    else {
        int m = (l+r);
        if(m&1) return getK(l,m/2)+1;
        else return getK(l,m/2-1)+1;
    }
}
int main() {
    scanf("%s",str+1);
    int n = strlen(str+1);
    for(int i = 1; i <= n; i ++) {
        dp[i][i] = 1;
        if(i+1 <= n && str[i] == str[i+1]) dp[i][i+1] = 1;
    }
    for(int i = 3; i <= n; i ++) {
        for(int j = 1; j <= n-i+1; j ++) {
            int r = j+i-1;
            if(dp[j+1][r-1] && str[j] == str[r]) dp[j][r] = 1;
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = i; j <= n; j ++) {
            ans[getK(i,j)] ++;
        }
    }
    for(int i = n; i > 0; i --)
        ans[i-1] += ans[i];
    for(int i = 1; i <= n; i ++)
        printf("%d%c",ans[i],(i==n?'\n':' '));
    return 0;
}
