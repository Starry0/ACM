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
        for(ll i = 0;; i ++) {
//            if(i == 0) cout << ((a^i)&(b^i)) << endl;
            if(((a^i)&(b^i)) == 0) {
                cout << i << endl;
                break;
            }
        }
    }


    return 0;
}