#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int n, m, ans;
int a[N], b[N];
int main() {
    // cin >> n >> m;
    scanf("%d%d",&n,&m);
    int c[m][n/m+1];
    int d[m], e[m];
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    memset(e, 0, sizeof(e));
    for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
    for(int i = 0; i < n; i ++) {
        b[a[i]%m] ++;
    }
    for(int i = 0; i < m; i ++) b[i] -= n/m;
    // for(int i = 0; i < m; i ++) printf("%d%c",b[i]," \n"[i==n-1]);
    int r = m-1;
    for(int i = m-1; i >= 0; i --) {
        while(b[i] > 0) {
            while(b[r] >= 0) r = (r+1)%m;
            c[i][d[i]] = (r-i+m)%m;
            ans += (r-i+m)%m;
            b[i]--;
            b[r]++;
            d[i]++;
        }
    }
    // for(int i = 0; i < m; i ++) printf("%d %d\n",i,vs[i].size() );
    cout << ans << endl;
    for(int i = 0; i < n; i ++) {
        int tmp = a[i]%m;
        if(d[tmp] != e[tmp]) {
            printf("%d ",a[i]+c[tmp][e[tmp]]);
            e[tmp]++;
        } else printf("%d ",a[i]);
    }
    return 0;
}
