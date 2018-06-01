#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
const int Inf = 1<<30;
int a[N], dp[N];
int t, n;
int main(){
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i = 0; i < n; i ++){
            scanf("%d",&a[i]);
            dp[i] = Inf;
        }
        for(int i = 0; i < n; i ++) {
            *upper_bound(dp,dp+n,a[i]) = a[i];
        }
        int ans = upper_bound(dp,dp+n,Inf-1) - dp;
        for(int i = 0; i < n; i ++) dp[i] = Inf;
        for(int i = 0; i < n/2; i ++){
            swap(a[i],a[n-i-1]);
        }
        for(int i = 0; i < n; i ++) {
            *upper_bound(dp,dp+n,a[i]) = a[i];
        }
        int ans1 = upper_bound(dp,dp+n,Inf-1) - dp;
        if(ans >= n-1 || ans1 >= n-1) cout << "YES\n";
        else cout << "NO\n";
        memset(a,0,sizeof(a));
    }
    return 0;
}
