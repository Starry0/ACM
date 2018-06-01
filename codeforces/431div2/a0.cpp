#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int a[N];
int main() {
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i], a[i] %=2;
    for(int i = 1; i <= n; i ++) {
        if(!a[1] || !a[n]) return 0*printf("No\n");
        if(a[i]) ans ++;
        else {
            if(a[i-1]) a[i] = 1,ans++;
        }
    }
    if(ans%2==0)printf("No\n");
    else printf("Yes\n");
    return 0;
}
