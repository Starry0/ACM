#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
const ll INF = 1e18+100;
ll n;
ll ans[50000], cnt = 0;
bool init() {
    for(ll i = 1; i < INF; i *= 2) {
        for(ll j = 1; j*i < INF; j *= 3) {
            for(ll k = 1; i*j*k < INF; k *= 5) {
                ans[cnt++] = i*j*k;
            }
        }
    }
}
int main() {
    int t;
    init();
    sort(ans, ans+cnt);
    cin >> t;
    while(t--) {
        cin >> n;
        printf("%lld\n",*lower_bound(ans+1, ans+cnt, n));
    }
    return 0;
}
