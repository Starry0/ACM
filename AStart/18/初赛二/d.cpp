/*#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 3e5+10;
ll a[N], t, n;

bool ok(ll y, ll sum) {
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] > y) {
            cnt2 += (a[i]-y)/2;
        } else if(a[i] <= y) {
            cnt1 += y-a[i];
        }
    }
    return cnt1 <= cnt2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> t;
    while(t--){
        cin >> n;
        ll ans = 0, l = INF, r = 0;
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
            ans += a[i];
            l = min(l, a[i]), r = max(r, a[i]);
        }
        ll cnt = -1;
        while(l <= r) {
            ll m = (l+r) >> 1;
            // cout << l << ' '<< r << ' ' << m << endl;
            int flag = ok(m, ans);
            // cout << flag << endl;
            if(flag == 1) {
                cnt = max(cnt, m);
                l = m+1;
            } else r = m -1;
        }
        cout << cnt << endl;
    }
    return 0;
}
*/
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 3e5+10;
ll a[N], t, n;

int ok(ll x){
    int pos = upper_bound(a ,a+n, x) - a;
    if(!(a[pos] > x)) return 2;
    ll cnt1 = 0;
    int tmp = 0;
    for(int i = pos; i < n; i ++) {
        if((a[i]-x)%2 == 0) {
            cnt1 += (a[i] - x)/2; 
            tmp = 1;
        } else cnt1 += (a[i]-x-1)/2;
    }
    ll cnt2 = 0 ;
    for(int i = 0;i < pos; i ++) {
        if(a[i] == x) break;
        cnt2 += (x-a[i]);
    }
    if(cnt2==cnt1 || (cnt1>=cnt2 && cnt1<cnt2+pos)) {
        return 1;
    }else if(cnt1 < cnt2) {
        return 2;
    } else {
        if(cnt1>=cnt2+pos && tmp) return 1;
        else return 3;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        ll MAX = 0;
        if(n == 1) {
            cout << a[0] << endl;
            continue;
        }
        sort(a,a+n);
        ll l = a[0], r = a[n-1];
        while(l +1 < r) {
            ll m = (l+r) >> 1;
            int flag = ok(m);
            if(flag == 1) {
                l = m;
            } else if(flag == 2) {
                r = m;
            } else l = m;
        }
        cout << l << endl;
    }
    return 0;
}
