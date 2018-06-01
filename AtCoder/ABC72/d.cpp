#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int i = 1; i < n; i ++) {
        if(a[i] == i) {
            swap(a[i], a[i+1]);
            ans++;
        }
    }
    if(a[n] == n) ans++;
    printf("%d\n",ans);
    return 0;
}
