#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N], n;
map<int,int> mp;
int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i ++) {
        scanf("%d",&a[i]);
        mp[a[i]] = 1;
    }
    sort(a,a+n);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < 32; j ++) {
            int x = 1 << j;
            if(mp[a[i]+x] && mp[a[i]+2*x]) {
                return 0*printf("3\n%d %d %d\n",a[i],a[i]+x,a[i]+x*2);
            }
            if(a[i]+x > a[n-1] || a[i]+2*x > a[n-1]) break;
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < 32; j ++) {
            int x = 1 << j;
            if(mp[a[i]+x]) {
                return 0*printf("2\n%d %d\n",a[i],a[i]+x);
            }
            if(mp[a[i]+x*2]) {
                return 0*printf("2\n%d %d\n",a[i],a[i]+2*x);
            }
            if(a[i]+x > a[n-1] || a[i]+2*x > a[n-1]) break;
        }
    }
    printf("1\n%d\n",a[0]);
    return 0;
}
