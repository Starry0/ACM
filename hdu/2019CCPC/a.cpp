//
// Created by starry on 2019/8/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;


int main() {
    ll t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        ll ans = 0;
        for(ll i = 0; i < 32; i ++) {
            int a1 = (a>>i)&1;
            int b1 = (b>>i)&1;
            if(a1 == 1 && b1 == 1) {
                ans += (1LL<<i);
            }
        }
        if(ans == 0) {
            for(int i = 0; i < 32; i ++) {
                int a1 = (a>>i)&1;
                int b1 = (b>>i)&1;
                if((a1 == 0 && b1 == 1) || (a1 == 1 && b1 == 0)) {
                    ans += (1LL<<i);
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}