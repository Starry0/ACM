#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        sort(a+1, a+1+n);
        int ans = 1;
        for(int i = n-1; i >= 1; i --) {
            if(a[i+1] - a[i] > k)break;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
