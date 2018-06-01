#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 30010;
struct Nod{
    int d, c;
}nod[N];
int MAX[N];
bool cmp(Nod &a, Nod &b) {
    if(a.d != b.d) return a.d < b.d;
    else return a.c > b.c;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n, m;
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i ++) cin >> nod[i].d >> nod[i].c;
        sort(nod+1,nod+1+n,cmp);
        for(int i = 1; i <= n; i ++) {
            MAX[i] = max(MAX[i-1],nod[i].c);
            // cout << MAX[i] << ' ' ;
        }
        // cout <<endl;
        while(m--) {
            int x, ans = 0;
            scanf("%d",&x);
            int l = 1, r = n;
            while(l <= r) {
                int m = (l+r)>>1;
                if(x >= nod[m].d) {
                    ans = MAX[m];
                    l = m+1;
                } else r = m-1;
            }
            printf("%d\n",ans);
            // cout << ans << endl;
        }
    }
    return 0;
}
