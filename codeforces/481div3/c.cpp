#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
ll a[N], b[N];
int main() {
    ll n, m;
    cin >> n >> m >> a[0];
    b[0] = a[0];
    for(int i = 1; i < n; i ++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    while(m--) {
        ll x;
        cin >> x;
        int id = lower_bound(b,b+n,x) -b;
        printf("%d %lld\n",id+1,a[id]-(b[id]-x));
    }
    return 0;
}
