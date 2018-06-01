#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 250010;
const int MOD = 1e9+7;
int a[MAX], b[MAX];
int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        for(int i = 1; i <= n; i ++) scanf("%d",&a[i]);
        a[n+1] = 0;
        for(int i = n; i > 0; i --){
            a[i] -= i;
            a[i] = max(a[i],a[i+1]);
            scanf("%d",&b[i]);
        }
        sort(b+1,b+1+n);
        int ans = 0, Max = 0;d
        for(int i = 1; i <= n; i ++) {
            int x = max(Max,a[b[i]]);
            ans = (ans+x) % MOD;
            Max = max(Max,x-n-i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
