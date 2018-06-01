#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
struct Nod{
    ll x, v;
}a[N], b[N];
bool cmp(Nod &x, Nod &y) {
    return x.x < y.x;
}
int main() {
    ll n, m, t;
    cin >> n >> m >> t;
    for(int i = 0; i < n; i ++) cin >> a[i].x >> a[i].v;
    for(int i = 0; i < m; i ++) cin >> b[i].x >> b[i].v;
    a[n].x = t;
    b[m].x = t;
    sort(a,a+n,cmp);
    sort(b,b+m,cmp);
    ll now = 0, a1 = 0, b1 = 0;
    ll ans = 0;
    while(now < t) {
        ll cnt;
        if(a[a1].v > b[b1].v) {
            cnt = a[a1].v;
        } else cnt = b[b1].v;
        ll pre = now;
        now = min(a[a1+1].x,b[b1+1].x);
        if(cnt > 0) ans += (now-pre)*cnt;
        if(now == t) break;
        if(now == a[a1+1].x) a1++;
        if(now == b[b1+1].x) b1++;
    }
    cout << ans << endl;
    return 0;
}
