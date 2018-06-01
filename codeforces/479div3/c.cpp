#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int a[N];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a,a+n);
    if(k == 0) {
        if(a[0] == 1) printf("-1\n");
        else printf("1\n");
        return 0;
    }
    if(a[k-1] == a[k]) printf("-1\n");
    else printf("%d\n",a[k-1]);
    return 0;
}
