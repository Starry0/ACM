#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 5e5+10;
int a[N], dp1[N], dp2[N], f[N];
int main() {
    int n, MAX = 0;
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    memset(f,INF,sizeof(f));
    for(int i = 0; i < n; i ++) {
        *upper_bound(f,f+n,a[i]) = a[i];
        dp1[i] = lower_bound(f,f+n,INF)-f;
    }
    for(int i = 0; i < n/2; i ++ )swap(a[i],a[n-i-1]);
    // for(int i = 0; i < n; i ++) printf("%d ", a[i]);printf("\n");
    memset(f,INF,sizeof(f));
    for(int i = 0; i < n; i ++) {
        *upper_bound(f,f+n,a[i]) = a[i];
        dp2[i] = lower_bound(f,f+n,INF)-f;
    }
    for(int i = 0; i < n; i ++) {
        // printf("%d %d\n",dp1[i],dp2[i]);
        MAX = max(MAX,dp1[i]+dp2[n-i-1]);
    }
    printf("%d\n",MAX-1);
    return 0;
}
