#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int Inf = 1<<30;
int a[1010],dp[1010];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF) {
        for(int i = 0; i <= n; i ++) dp[i] = Inf;
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        for(int i = 0; i < n; i ++) {
            *lower_bound(dp,dp+n,a[i]) = a[i];
        }
        //printf("%d\n",lower_bound(dp,dp+n,Inf)-dp);
        cout << lower_bound(dp,dp+n,Inf)-dp << endl;
    }
    return 0;
}
