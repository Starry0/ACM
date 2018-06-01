#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
    int n, k, x;
    scanf("%d %d", &n, &k);
    int ans = n*2, ans1 = n;
    for(int i = 0; i < k; i ++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < k; i ++) {
        int d = min(a[i]/4, ans1);
        ans1 -= d;
        a[i] -= d*4;
    }
    ans += ans1;
    for(int i = 0; i < k; i ++) {
        int d = min(a[i]/2, ans);
        ans -= d;
        a[i] -= d*2;
    }
    ans += ans1;
    for(int i = 0; i < k; i ++) {
        ans -= a[i];
    }
    if(ans < 0) printf("NO\n");
    else printf("YES\n");
    return 0;
}
